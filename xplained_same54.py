from base import *
from devices import *
import time

class XplainedProSamE54(Board):
    ids_vendor = {
        "03EB":frozenset(("2111",))
    }

    @staticmethod
    def match(dev):
        return dev["vid"] in XplainedProSamE54.ids_vendor and dev["pid"] in XplainedProSamE54.ids_vendor[dev["vid"]]

    def reset(self):
        # hack to reset
        proc.runcmd("edbg_c21n", "-F", "r,1,1", "-t", "same54")

    def burn(self,bin,outfn=None):
        fname = fs.get_tempfile(bin)
        outfn(fname)
        res,out,err= proc.runcmd("edbg_c21n", "-ebpv", "-t", "same54","-s",self.sid,"-f", fname,outfn=outfn)
        fs.del_tempfile(fname)
        if res:
            return False,out
        return True,out
