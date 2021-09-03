#!/usr/bin/python3

""" script that reads stdin line by line and computes metrics """

import sys


def printstdin(date, size):
    """ print information from stdin """
    print("File size: {:d}".format(size))
    for i in sorted(date.keys()):
        if date[i] != 0:
            print("{}: {:d}".format(i, date[i]))


statusCode = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0,
              "404": 0, "405": 0, "500": 0}

counter = 0
size = 0

try:
    for line in sys.stdin:
        if counter != 0 and counter % 10 == 0:
            printstdin(statusCode, size)

        listStatus = line.split()
        counter += 1

        try:
            size += int(listStatus[-1])
        except:
            pass

        try:
            if listStatus[-2] in statusCode:
                statusCode[listStatus[-2]] += 1
        except:
            pass
    printstdin(statusCode, size)


except KeyboardInterrupt:
    printstdin(statusCode, size)
    raise
