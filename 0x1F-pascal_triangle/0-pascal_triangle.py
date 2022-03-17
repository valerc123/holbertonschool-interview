#!/usr/bin/python3

"""
    Function that returns a list of lists of integers representing the Pascal’s triangle of n:
    Returns an empty list if n <= 0
"""

def pascal_triangle(n):
    lista = []
    if n <= 0:
        return list()
    for i in range(n):
        lista.append([])
        lista[i].append(1)
        for m in range(1, i):
            lista[i].append(lista[i - 1][m - 1] + lista[i - 1][m])
        if(i != 0):
            lista[i].append(1)
