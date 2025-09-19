#!/usr/bin/python3
"""Get the stats from a log file"""
import sys
import re


def print_result(size, status_codes):
    """Prints the total file size and status code counts"""
    print("File size: {}".format(size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] != 0:
            print("{}: {}".format(code, status_codes[code]))


def main():
    """Processes log lines from stdin and prints stats"""
    status_codes_list = [200, 301, 400, 401, 403, 404, 405, 500]
    status_codes = {code: 0 for code in status_codes_list}
    total_size = 0
    valid_line_count = 0

    try:
        for line in sys.stdin:
            line = line.strip()

            # Find the status code in the line
            pattern_status = r'(\d{3}) \d+'
            match_status = re.search(pattern_status, line)
            if not match_status:
                print(line)
                # pattern_size = r'(\d+)$'
                # match_size = re.search(pattern_size, line)
                # file_size = int(match_size.group(1))

                # total_size += file_size
                continue

            status_code = int(match_status.group(1))
            if status_code in status_codes:
                status_codes[status_code] += 1

            # Find the size in the line
            pattern_size = r'\d{3} (\d+)'
            match_size = re.search(pattern_size, line)
            file_size = int(match_size.group(1))

            total_size += file_size

            valid_line_count += 1

            if valid_line_count % 10 == 0:
                print_result(total_size, status_codes)

    except KeyboardInterrupt:
        print_result(total_size, status_codes)
        raise

    # Always print final result — even if no valid lines
    if valid_line_count % 10 != 0 or valid_line_count == 0:
        print_result(total_size, status_codes)


if __name__ == "__main__":
    main()
