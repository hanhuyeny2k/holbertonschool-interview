#!/usr/bin/python3


def minOperations(n):
    """calculate the newest number of operations needed to
       result an exact n H characters in the file"""
    counter = 0
    for i in range(2, n + 1):
        while n % i == 0:
            n = n / i
            counter += i
    return counter
