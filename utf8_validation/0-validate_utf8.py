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
        return True

    result_single_bytes = False
    result_two_bytes = False
    result_three_bytes = False
    result_four_bytes = False
    result_global = False

    number_single_bytes = 0
    list_idx_single_bytes = []
    number_two_bytes = 0
    list_idx_two_bytes = []
    number_three_bytes = 0
    list_idx_three_bytes = []
    number_four_bytes = 0
    list_idx_four_bytes = []

    for idx, byte in enumerate(data):
        last_eight_bits = byte % 256
        if last_eight_bits <= 127:
            number_single_bytes += 1
            list_idx_single_bytes.append(idx)
        if last_eight_bits >= 192 and byte <= 223:
            number_two_bytes += 1
            list_idx_two_bytes.append(idx)
        if last_eight_bits >= 224 and byte <= 239:
            number_three_bytes += 1
            list_idx_three_bytes.append(idx)
        if last_eight_bits >= 240 and byte <= 247:
            number_four_bytes += 1
            list_idx_four_bytes.append(idx)
        if last_eight_bits >= 248:
            return False  # Invalid UTF-8 no 5 bytes encoding

    # Check if the array given is filled only with bytes lower than 127
    # so in UTF-8 it is encoded with only one byte
    if size_array == number_single_bytes:
        return True

    # Verify for one bytes
    verif_single = len(list_idx_single_bytes) != 0
    if verif_single:
        for idx_start in list_idx_single_bytes:
            if data[idx_start] > 192:
                return False
        result_single_bytes = True

    # Verify for two bytes
    verif_two = len(list_idx_two_bytes) != 0
    if verif_two:
        for idx_start in list_idx_two_bytes:
            if idx_start + 2 > size_array:
                return False
            if idx_start < idx_start + 2:
                continue
            for i in range(1, 3):
                if data[idx_start + i] > 192:
                    return False
        result_two_bytes = True

    # Verify for three bytes
    verif_three = len(list_idx_three_bytes) != 0
    if verif_three:
        for idx_start in list_idx_three_bytes:
            if idx_start + 3 > size_array:
                return False
            for i in range(1, 3):
                if data[idx_start + i] > 192:
                    return False
        result_three_bytes = True

    verif_four = len(list_idx_four_bytes) != 0
    if verif_four:
        for idx_start in list_idx_four_bytes:
            if idx_start + 4 > size_array:
                return False
            for i in range(1, 4):
                if data[idx_start + i] > 192:
                    return False
        result_four_bytes = True

    verifications = [
        (verif_single, result_single_bytes),
        (verif_two, result_two_bytes),
        (verif_three, result_three_bytes),
        (verif_four, result_four_bytes)
    ]

    result_global = all(
        not verif or result
        for verif, result in verifications
    )

    return result_global
