#!/usr/bin/python3
"""[summary]
"""

def minOperations(n):
    """[summary]

    Args:
        n ([type]): [description]
"""
    if n <= 1:
        return 0
    num = 0
    module = 2
    while n > 1:
        if n % module == 0:
            n = n / module
            num = num + module
        else:
            module += 1
    return num