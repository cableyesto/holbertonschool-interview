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

    # Strict log line format
    log_pattern = re.compile(
        r'^\d{1,3}(?:\.\d{1,3}){3} - \['
        r'\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d+'
        r'\] "GET /projects/260 HTTP/1\.1" (\d{3}) (\d+)$'
    )

    try:
        for line in sys.stdin:
            line = line.strip()
            match = log_pattern.match(line)
            if not match:
                continue  # Skip invalid lines

            status_code = int(match.group(1))
            file_size = int(match.group(2))

            total_size += file_size
            if status_code in status_codes:
                status_codes[status_code] += 1

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
