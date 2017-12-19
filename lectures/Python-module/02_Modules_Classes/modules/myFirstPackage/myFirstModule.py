def f0():
    return f1() # f1 is in scope

def f1():
    return __name__
