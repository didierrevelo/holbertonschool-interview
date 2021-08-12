#!/usr/bin/python3
"""0. Minimum Operations"""


def minOperations(n):
    """minOperations
        n -- If n is impossible to achieve, return 0
        Return: Returns an integer
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
