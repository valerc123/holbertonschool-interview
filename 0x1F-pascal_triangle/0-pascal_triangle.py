#!/usr/bin/python3
"""
returns a list of lists of integers representing the Pascal’s triangle
"""


def pascal_triangle(n):
    """
     Pascal's Triangle
    """
    if n <= 0:
        return ([])

    triangle = []
    index = 1
    while index < n + 1:
        j = index
        c = 0
        n_level = [1]
        while j > 2:
            n_level.append(triangle[-1][c] + triangle[-1][c + 1])
            j -= 1
            c += 1
        if index > 1:
            n_level.append(1)
        triangle.append(n_level)
        index += 1
    return (triangle)