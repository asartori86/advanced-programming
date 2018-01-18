from _10_operators_magics import Number_i

a = Number_i(0)
print(a)
print(a.__str__())
print(a.__repr__())
print(a+1)
a+=1
print(a)
print(a-10)
a-=10
print(a)
print(a<Number_i(0))
try:
    print(a>0)
except TypeError as err: 
    print(err)
