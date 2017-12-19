from ..subPackage_1 import usefulSubModule as s

def f0():
    return s.usefulFunction()

if __name__ == "__main__":
    print(f0())
