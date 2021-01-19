#!/usr/bin/python3
"""Rotate 2D Matrix"""


def swap(matrix, i, j, x=None):
    """Swaps the values of an matrix
    """
    if not x:
        matrix[i][j] = matrix[i][j] * matrix[j][i]
        matrix[j][i] = matrix[i][j] // matrix[j][i]
        matrix[i][j] = matrix[i][j] // matrix[j][i]
    else:
        matrix[i][j] = matrix[i][j] * matrix[i][x]
        matrix[i][x] = matrix[i][j] // matrix[i][x]
        matrix[i][j] = matrix[i][j] // matrix[i][x]


def rotate_2d_matrix(matrix):
    """Rotates a matrix in place 90 degrees
    """
    for i in range(len(matrix)):
        for j in range(i + 1, len(matrix[i])):
            swap(matrix, i, j)

    for i in range(len(matrix)):
        a = 0
        b = len(matrix) - 1
        while a < b:
            swap(matrix, i, a, b)
            a += 1
            b -= 1
