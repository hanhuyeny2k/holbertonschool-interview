#!/usr/bin/python3
"""
determines if a given data set represents a valid UTF-8
"""

def validUTF8(data):
    """Return True if data is a valid UTF-8 encoding,
       else return False
    """
    try:
        temp = []
        for i in data:
            temp.append(i & 0xff)
        bytes(temp).decode()
        return True
    except UnicodeDecodeError:
        return False

