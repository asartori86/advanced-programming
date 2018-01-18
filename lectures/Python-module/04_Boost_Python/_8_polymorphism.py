from _8_polymorphism import Interface, obj1, obj2, factory

print('\nImporting C++ Interface')
a = Interface() 
try:
    a.foo()     # pure_virtual flag, cannot be called
except RuntimeError as err:
    print(' ->',err)

print('\nCreating polymorphic object from C++ Interface')
class A(Interface): 
    def foo(self): return 'from this specific object created in Python'
a = A()
print(' -> calling foo...',a.foo()) # I can call a.foo()

print('\nImporting polymorphic object from C++')
a = obj1()
print(' -> calling foo...',a.foo()) # I can call a.foo()
a = obj2()
print(' -> calling foo...',a.foo()) # I can call a.foo()

print('\nUsing factory design pattern')
for i in [1,2]:
    a = factory(i)   # factory to instantiate objects defined in C++ 
    print(' -> calling foo...',a.foo()) # I can call a.foo()
print("...returning nullptr...")
try:
    a = factory()
    print(' -> calling foo...',a.foo()) 
except: 
    print('does not work') 

