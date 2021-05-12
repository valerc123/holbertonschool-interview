#!/usr/bin/python3

'''
    Calculates the minimum number of operations to reach n.
'''


def minOperations(n):
    """
        Finds the min operations
    """
    _str = "H"
    count = 0
    copy = ""
    if n <= 1:
        return 0

    while(len(_str) < n):
        if (n % len(_str) == 0):
            copy = _str
            count += 1
        _str += copy
        count += 1
    return count
