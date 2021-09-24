#!/usr/bin/python3
""" UTF-8 Validation """


def validUTF8(data):
    """
    Method that determines if a given data set represents a valid
    UTF-8 encoding.
    Return: True if data is a valid UTF-8 encoding, else return False
    A character in UTF-8 can be 1 to 4 bytes long
    The data set can contain multiple characters
    The data will be represented by a list of integers
    Each integer represents 1 byte of data, therefore you only
    need to handle the 8 least significant bits of each integer
    """
    bytes = 0

    rain1 = 1 << 7
    rain2 = 1 << 6

    for i in data:

        n_byte = 1 << 7

        if bytes == 0:
            while n_byte & i:
                bytes += 1
                n_byte = n_byte >> 1

            if bytes == 0:
                continue

            if bytes == 1 or bytes > 4:
                return False

        else:
            if not (i & rain1 and not (i & rain2)):
                    return False

        bytes -= 1

    if bytes == 0:
        return True

    return False
