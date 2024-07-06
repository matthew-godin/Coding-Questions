from itertools import permutations
from math import inf

def add_row(square, first, last, p):
    row = []
    for i in range(first, last):
        row.append(p[i])
    square.append(row)
    
def is_magic_square(square):
    magic_constant = sum(square[0])
    for i in range(1, 3):
        if magic_constant != sum(square[i]):
            return False
    for i in range(3):
        constant = 0
        for j in range(3):
            constant += square[j][i]
        if magic_constant != constant:
            return False
    if magic_constant != square[0][0] + square[1][1] + square[2][2]:
        return False
    if magic_constant != square[2][0] + square[1][1] + square[0][2]:
        return False
    return True
    
def get_diff(s, square):
    total = 0
    for i in range(3):
        for j in range(3):
            total += abs(s[i][j] - square[i][j])
    return total

def formingMagicSquare(s):
    min_cost = inf
    for p in permutations(list(range(1, 10))):
        square = []
        add_row(square, 0, 3, p)
        add_row(square, 3, 6, p)
        add_row(square, 6, 9, p)
        if is_magic_square(square):
            cost = get_diff(s, square)
            if cost < min_cost:
                min_cost = cost
    return min_cost