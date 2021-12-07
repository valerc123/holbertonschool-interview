#!/usr/bin/python3

""" Module that validates valid UTF-8 encoding """


def validUTF8(data):
    """ Validates UTF-8 encoding """

    string = bytes([i & 255 for i in data])
    print(string)
    try:
        string.decode("UTF-8", "strict")
        return True
    except Exception:
        return False
    
