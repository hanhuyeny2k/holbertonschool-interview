#!/usr/bin/python3
import sys


file_size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0,
                403: 0, 404: 0, 405: 0, 500: 0}


def print_stats(file_size, status_codes):
    """Print log statistics"""
    print('File size: {}'.format(file_size))
    for key in sorted(status_codes):
        if status_codes[key] > 0:
            print('{}: {}'.format(key, status_codes[key]))


if __name__ == "__main__":
    try:
        for linenum, line in enumerate(sys.stdin, 1):
            fields = line.split()
            if len(fields) < 6:
                pass
            file_size += int(fields.pop())
            status_codes[int(fields.pop())] += 1
            if linenum % 10 == 0:
                print_stats(file_size, status_codes)
    except KeyboardInterrupt:
        print_stats(file_size, status_codes)
        raise
