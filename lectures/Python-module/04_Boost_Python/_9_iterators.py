from __iterators import iterator_d,iterator_s

print("\nfill the iterator")
a = iterator_s()
for i in 'supercaligragilistichespiralidoso': 
    a.add(i)

print("\nloop the iterator using range")
for i in a.range():
    print(i)


print("\nfill the iterator")
a = iterator_d()
for i in range(10):
    a.add(i)

print("\nloop the iterator using range")
for i in a.range():
    print(i)


