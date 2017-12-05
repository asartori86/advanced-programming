import inspect 

def is_palindrome(string_var):     
    '''
    ex_1
    '''
    fname = inspect.stack()[0][3]
    ret = None
    ########################
    # code here
    ########################
    assert ret is not None, fname+' is not defined'
    assert type(ret) is type(True), fname+' should return a bool'
    if string_var is 'abcdefgfedcba': assert ret is True, 'failed abcdefgfedcba' 
    if string_var is 'pippo': assert ret is False, 'failed pippo' 
    if string_var is 'madamimadam': assert ret is True, 'failed madamimadam' 
    return ret 

def histogram_letters(string_var):     
    '''
    ex_2
    '''
    fname = inspect.stack()[0][3]
    ret = None
    ########################
    # code here
    ########################
    assert ret is not None, fname+' is not defined'
    assert type(ret) is type({}), fname+' should return a dict'
    if string_var is 'aabb': assert ret == {'a':2,'b':2}, 'failed aabb' 
    if string_var is 'abbccddddeeeeeffffff': assert ret == {'a':1,'b':2,'c':2,'d':4,'e':5,'f':6}, 'failed abbccddddeeeeeffffff' 
    if string_var is '1.223344': assert ret == {'.':1,'1':1,'2':2,'3':2,'4':2}, 'failed 1.223344'
    return ret 

def get_most_frequent(list_var):
    '''
    ex_3
    '''
    fname = inspect.stack()[0][3]
    ret = None
    ########################
    # code here
    ########################
    assert ret is not None, fname+' is not defined'
    assert type(ret) is type(()), fname+' should return a tuple'
    if list_var == [3,3,3,2,2,1]: assert ret == (3,3), 'failed [3,3,3,2,2,1]'
    if list_var == [0,0,0,0,1]: assert ret == (0,4), 'failed [0,0,0,0,1]'
    return ret

def which_duplicates(list_var):
    '''
    ex_4
    '''
    fname = inspect.stack()[0][3]
    ret = None
    ########################
    # code here
    ########################
    assert ret is not None, fname+' is not defined'
    assert type(ret) is type({}), fname+' should return a dict'
    if list_var == [3,3,3,2,2,1]: assert ret == {'3':3,'2':2}, 'failed [3,3,3,2,2,1]'
    if list_var == [0,0,0,0,1]: assert ret == {'0':4}, 'failed [0,0,0,0,1]'
    return ret


def compute_factorial(int_val):
    '''
    ex_5
    '''
    fname = inspect.stack()[0][3]
    ret = None
    ########################
    # code here
    ########################
    assert ret is not None, fname+' is not defined'
    assert type(ret) is type(1), fname+' should return an integer'
    if int_val is 0: assert ret == 1     , 'failed 0'
    if int_val is 1: assert ret == 1     , 'failed 1'
    if int_val is 2: assert ret == 2     , 'failed 2'
    if int_val is 6: assert ret == 720   , 'failed 6'
    if int_val is 9: assert ret == 362880, 'failed 9'
    return ret


def is_prime(int_val):
    '''
    ex_6
    '''
    fname = inspect.stack()[0][3]
    ret = None
    ########################
    # code here
    ########################
    assert ret is not None, fname+' is not defined'
    assert type(ret) is type(False), fname+' should return a bool'
    if int_val == 0: assert ret is False   , 'failed 0'
    if int_val == 1: assert ret is False   , 'failed 1'
    if int_val == 2: assert ret is True    , 'failed 2'
    if int_val == 3: assert ret is True    , 'failed 3'
    if int_val == 19: assert ret is True   , 'failed 19'
    if int_val == 50: assert ret is False  , 'failed 50'
    if int_val == 65: assert ret is False  , 'failed 65'
    if int_val == 71: assert ret is True  , 'failed 71'
    if int_val == 73: assert ret is True   , 'failed 73'
    if int_val == 157: assert ret is True  , 'failed 157'
    return ret

def is_divisor(int_val,div):
    '''
    ex_7
    '''
    fname = inspect.stack()[0][3]
    ret = None
    ########################
    # code here
    ########################
    assert ret is not None, fname+' is not defined'
    assert type(ret) is type(False), fname+' should return a bool'
    if int_val == 4 and div == 2: assert ret is True, 'failed 4/2'
    if int_val == 15 and div == 5: assert ret is True, 'failed 15/5'
    if int_val == 11 and div == 5: assert ret is False, 'failed 11/5'
    return ret


def which_divisors(int_val): 
    '''
    ex_8
    '''
    fname = inspect.stack()[0][3]
    ret = None
    ########################
    # code here
    ########################
    assert ret is not None, fname+' is not defined'
    assert type(ret) is type([]), fname+' should return a list'
    if int_val == 4: assert ret == [2]    , 'failed 4'
    if int_val == 10: assert ret == [2,5] , 'failed 10'
    if int_val == 13: assert ret == []    , 'failed 13'
    return ret


def which_prime_divisors(int_val): 
    '''
    ex_9
    '''
    fname = inspect.stack()[0][3]
    ret = None
    ########################
    # code here
    ########################
    assert ret is not None, fname+' is not defined'
    assert type(ret) is type([]), fname+' should return a list'
    if int_val == 6: assert ret == [2,3], 'failed 3'
    if int_val is 10: ret == [2,5], 'failed 10'
    if int_val is 13: ret == [], 'failed 13'
    return ret



if __name__ == "__main__":
    tests=[\
            "is_palindrome('abcdefgfedcba')",\
            "is_palindrome('pippo')",\
            "is_palindrome('madamimadam')",\
            "histogram_letters('aabb')",\
            "histogram_letters('abbccddddeeeeeffffff')",\
            "histogram_letters('1.223344')",\
            "get_most_frequent([3,3,3,2,2,1])",\
            "get_most_frequent([0,0,0,0,1])",\
            "which_duplicates([3,3,3,2,2,1])",\
            "which_duplicates([0,0,0,0,1])",\
            "compute_factorial(0)",\
            "compute_factorial(1)",\
            "compute_factorial(2)",\
            "compute_factorial(6)",\
            "compute_factorial(9)",\
            "is_prime(0)",\
            "is_prime(1)",\
            "is_prime(2)",\
            "is_prime(3)",\
            "is_prime(50)",\
            "is_prime(65)",\
            "is_prime(71)",\
            "is_prime(73)",\
            "is_prime(19)",\
            "is_prime(157)",\
            "is_divisor(4,2)",\
            "is_divisor(15,5)",\
            "is_divisor(11,5)",\
            "which_divisors(4)",\
            "which_divisors(10)",\
            "which_divisors(13)",\
            "which_prime_divisors(6)",\
            "which_prime_divisors(10)",\
            "which_prime_divisors(13)",\
          ]
    for t in tests:
        try:
            print(t,end='\t-> ')
            print(eval(t))
        except AssertionError as err:
            print("ERROR: ",err) 
        

