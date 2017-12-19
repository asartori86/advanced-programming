import argparse

if __name__ == "__main__":

    # nargs=int: int arguments
    #       '?': 0 or 1 arguments
    #       '*': 0 or many arguments
    #       '+': Many, at least one, argument
    parser = argparse.ArgumentParser(description=\
            'here you can describe what this program does')
    parser.add_argument('-a','--same-of-a',help='-a needs no argument',nargs='?') # -a is the same of --same-of-a, expect 0 or 1 argument 
    parser.add_argument('-b',help='-b needs 1 arg',nargs=1) # -b expects 1 argument
    parser.add_argument('-c',help='-c needs 2 args',nargs=2) # -c expects 2 arguments
    parser.add_argument('-d',help='-d accepts all arguments',nargs='*') # -c expects 2 arguments
    parser.add_argument('--set-this-param-to=',help='instructions for --set-this-param-to',nargs=1) # --set-this-param-to expects 1 arg
    parser.add_argument('this-setting',help='setting needs no arguments',nargs='?') 
    args = parser.parse_args()
    print("{}\n".format(args) )
