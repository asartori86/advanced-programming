import getopt, sys

if __name__ == "__main__":
    # getopt.getopt(argv, options[, long_options]) 
    # argv is a list containing all string to parse
    # options are preceded by -
    #  -> if an argument is needed, use :
    # long_options are preceded by --
    #  -> if an argument is needed, use =
    argv = sys.argv[:]
    opts,args = getopt.getopt(argv[1:],\
                              'ab:c:',\
                              ['just-a-flag',\
                               'set-this-param-to=',\
                               'same-of-a']) 

    print("sys.argv -> {}\n".format(argv))
    print("opts -> {} \nargs -> {}\n".format(opts,args) )
