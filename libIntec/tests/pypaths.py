
# @author Shady, Ganem <shady.ganem@intel.com>

import argparse

parser = argparse.ArgumentParser()

parser.add_argument('-p', "--path", help="path of interset", required=True)

args = parser.parse_args()
args = vars(args)

if args["path"] == "site-packages":
    import sys
    sp_paths = list()
    for path in sys.path:
        if "site-packages" in path and "/usr/lib/" in path:
            if len(path.split("/")) == 5:
                print(path)

