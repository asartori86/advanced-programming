from _4_members import Greetings

g = Greetings('Jacopo')

# greet is unreachable (no read/write)
try: 
    print(g.greet()) 
except AttributeError as err: 
    print('ERR:',err) 

# greetings is readable
print(g.greetings) 
# but not writable
try: 
    g.greetings = 'cannot be changed'
except AttributeError as err: 
    print('ERR:',err) 

# name2greet is readable and writable
print(g.name2greet) # Jacopo
g.name2greet = 'Alberto'
print(g.name2greet) # Alberto 
