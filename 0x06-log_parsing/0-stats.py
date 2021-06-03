#!/usr/bin/python3

"""Reads stdin line by line & computes metrics."""

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
    for line in sys.stdin:
        arr = line.split(" ")
        lines += 1
        fileSize += int(arr[8])
        if(arr[7] == '200'):
            status["200"] += 1
        elif (arr[7] == '301'):
            status["301"] += 1
        elif (arr[7] == '400'):
            status["400"] += 1
        elif (arr[7] == '401'):
            status["401"] += 1 
        elif (arr[7] == '403'):
            status["403"] += 1
        elif (arr[7] == '404'):
            status["404"] += 1
        elif (arr[7] == '405'):
            status["405"] += 1
        elif (arr[7] == '500'):
            status["500"] += 1

        if (lines == 10):
            lines = 0
            print("File size: {0}".format(fileSize))
            print("200: {0}".format(status["200"]))
            print("301: {0}".format(status["301"]))
            print("400: {0}".format(status["400"]))
            print("401: {0}".format(status["401"]))
            print("403: {0}".format(status["403"]))
            print("404: {0}".format(status["404"]))
            print("405: {0}".format(status["405"]))
            print("500: {0}".format(status["500"]))
