#!/usr/bin/python3
"""
Validation utf-8
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding
    The data will be represented by a list of integers
    Each integer represents 1 byte of data,
    therefore you only need to handle the 8 least significant bits
    of each integer
    """
    if isinstance(data, list) is not True:
        return False
    size_array = len(data)
    if size_array == 0:
        return False

    number_single_bytes = 0
    number_two_bytes = 0
    list_idx_two_bytes = []
    number_three_bytes = 0
    list_idx_three_bytes = []
    number_four_bytes = 0
    list_idx_four_bytes = []

    for idx, byte in enumerate(data):
        if byte <= 127:
            number_single_bytes += 1
        if byte >= 128 and byte <= 2047:
            number_two_bytes += 1
            list_idx_two_bytes.append(idx)
        if byte >= 2048 and byte <= 65535:
            number_three_bytes += 1
            list_idx_three_bytes.append(idx)
        if byte >= 65536 and byte <= 1114111:
            number_four_bytes += 1
            list_idx_four_bytes.append(idx)

    # Check if the array given is filled only with bytes lower than 127
    # so in UTF-8 it is encoded with only one byte
    if size_array == number_single_bytes:
        return True
    # Verify for two bytes
    for idx_start in list_idx_two_bytes:
        if idx_start + 2 > size_array:
            return False
        if idx_start < idx_start + 2:
            continue
        for i in range(1, 3):
            if data[idx_start + i] > 192:
                return False
    return True
