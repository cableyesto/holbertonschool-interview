#!/usr/bin/python3
"""
Get the stats from a log file
"""
import sys
import re


def print_result(size, status_codes):
    """Documentation of the print function"""
    print("File size: {}".format(size))
    for key, value in status_codes.items():
        print("{}: {}".format(key, value))


try:
    status_codes_init = {}
    status_codes_list = [200, 301, 400, 401, 403, 404, 405, 500]
    i = 0
    size = 0

    for item in status_codes_list:
        status_codes_init.update({item: 0})

    status_codes = status_codes_init.copy()

    for line in sys.stdin:

        # Find the status code in the line
        pattern_status = r'(\d{3}) \d+'
        match_status = re.search(pattern_status, line)
        current_status = int(match_status.group(1))

        # Find the size in the line
        pattern_size = r'\d{3} (\d+)'
        match_size = re.search(pattern_size, line)
        current_size = int(match_size.group(1))

        if (i < 10):
            size += current_size
            if current_status in status_codes_list:
                status_codes[current_status] += 1

            i += 1
            print_result(size, status_codes)

            if (i == 9):
                size = 0
                status_codes = status_codes_init.copy()
                i = 0
                print_result(size, status_codes)

except KeyboardInterrupt:
    print_result(size, status_codes)
except Exception as e:
    print("An error occured: {}".format(e))
