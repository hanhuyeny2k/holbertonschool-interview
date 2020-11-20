#!/usr/bin/python3
"""Calculate how much water will be retained after it rains"""


def rain(walls):
    """return integer indicating total amount of rainwater retained"""
    n = len(walls)
    left_max = 0
    right_max = 0
    result = 0
    lo = 0
    hi = n-1
    if walls is None:
        return 0
    while(lo <= hi):
        if(walls[lo] < walls[hi]):
            if(walls[lo] > left_max):
                left_max = walls[lo]
            else:
                result += left_max - walls[lo]
            lo += 1
        else:
            if(walls[hi] > right_max):
                right_max = walls[hi]
            else:
                result += right_max - walls[hi]
            hi -= 1
    return result
