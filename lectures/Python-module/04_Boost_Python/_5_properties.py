from _5_properties import Greetings

g = Greetings('Jacopo')

# greetings is readable
print(g.greetings) # this expression calls the getter 
                   # Hello Jacopo
# and writable
g.greetings = 'Alberto' # this expression calls the setter
print(g.greetings) # this expression calls the getter 
                   # Hello Alberto 

# name2greet is readable and writable
print(g.name2greet) # Jacopo
# but not writable 
try:
    g.name2greet = 'Alberto' # no setter for this property
except AttributeError as err: 
    print('ERR:',err,'| missing setter for name2greet property')
