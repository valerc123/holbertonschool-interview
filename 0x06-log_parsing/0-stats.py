#!/usr/bin/python3

"""Reads stdin line by line & computes metrics."""
from time import sleep
import random
import sys

if __name__ == "__main__":
    lines = 0
    fileSize = 0
    status = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0
    }

    try:
        for line in sys.stdin:
            arr = line.split(" ")
            lines += 1
            fileSize += int(arr[-1])
            code = arr[-2]
            if(code in line):
                status[code] += 1
            if lines == 10:
                lines = 0
                print(f"File size: {fileSize}")
                for key, value in status.items():
                    if value != 0:
                        print(f"{key}: {value}")
                    fileSize = 0
                status = dict.fromkeys(status, 0)
    except KeyboardInterrupt as err:
        print(f"File size: {fileSize}")
        for key, value in status.items():
            if value != 0:
                print(f"{key}: {value}")
    finally:
        sleep(random.random())
