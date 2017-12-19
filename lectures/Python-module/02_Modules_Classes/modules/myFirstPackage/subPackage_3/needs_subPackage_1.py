import os,sys
file_path = os.path.abspath(__file__)
this_subpackage_path = os.path.split(file_path)[0]
this_package_path = os.path.join(this_subpackage_path,'../..')
sys.path.insert(0, this_package_path)

from myFirstPackage.subPackage_1 import usefulSubModule as s

def f0():
    return s.usefulFunction()
if __name__ == "__main__":
    print(f0())
