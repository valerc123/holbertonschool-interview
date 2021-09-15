#!/usr/bin/python3

"""
    Calculate how much water will be retained after it rains
"""


def rain(walls):
    """
        Given a list of non-negative integers representing walls of width 1,
        calculate how much water will be retained after it rains
        Args:
            walls: a list of non-negative integers
        Returns:
            Integer indicating total amount of rainwater retained
    """
    lenWalls = len(walls)
    water = 0

    for i in range(1, (lenWalls - 1)):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]

        for j in range((i + 1), lenWalls):
            right = max(right, walls[j])

        water = water + (min(left, right) - walls[i])
    return water
