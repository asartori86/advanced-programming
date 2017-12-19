import myFirstModule as m

def f0():
    return __name__

def f1():
    return m.__name__

if __name__ == "__main__": 
    print("this module's name is "+f0())
    print("sys module's name is "+f1())
