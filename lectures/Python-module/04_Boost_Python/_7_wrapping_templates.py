from _7_wrapping_templates import Foo_int,Foo_float,Foo_double

f = Foo_int()
print(f.value)
f = Foo_float()
print(f.value, "  <- float has ~7 mantissa significant digits ") 
f = Foo_double()
print(f.value, "  <- double has ~16 mantissa significant digits ") 

