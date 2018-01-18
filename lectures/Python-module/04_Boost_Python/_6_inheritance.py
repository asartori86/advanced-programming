from _6_inheritance import Derived1,Derived2 

print('\nInheritance')
print('-- default constructor --')
d01 = Derived1()
print('-- <str> constructor --')
d11 = Derived1('str1')
print('-- <str,str> constructor --')
try: 
    d21 = Derived1('str1','str2')
except: 
    print(' missing constructor <str,str> ')

print('\nMultiple Inheritance')
print('-- default constructor --')
d02 = Derived2()
print('-- <str> constructor --')
try: 
    d01 = Derived2('str1')
except: 
    print(' missing constructor <str> ')
print('-- <str,str> constructor --')
d02 = Derived2("str1","str2")
