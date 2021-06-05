#!/usr/bin/python3

"""Reads stdin line by line & computes metrics."""
import sys

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
        arguments = line.split(" ")
        if len(arguments) > 2:
            code = arguments[-2]
            fileSize += int(arguments[-1])
            lines += 1
            if code in status:
                status[code] += 1
            if lines == 10:
                print(f"File size: {fileSize}")
                for key, value in sorted(status.items()):
                    if value != 0:
                        print(f"{key}: {value}")
                line = 0
except KeyboardInterrupt:
    pass
finally:
    print(f"File size: {fileSize}")
    for key, value in sorted(status.items()):
        if value != 0:
            print(f"{key}: {value}")
