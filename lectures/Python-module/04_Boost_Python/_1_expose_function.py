from _1_expose_function import simple,auto_foo,defval_foo

print(simple())

auto_foo()
auto_foo(True)
auto_foo(True,1)
auto_foo(True,1,'a')
try: 
    auto_foo('a') # ERROR
except: 
    print("\nauto_foo('a') causes an error\n")

defval_foo(True)            # 1
defval_foo(False,-10)       # 0 -10
defval_foo(True,100,'1000') # 1 100 1000
try: 
    defval_foo('a') # ERROR
except: 
    print("\ndefval_foo('a') causes an error\n")
