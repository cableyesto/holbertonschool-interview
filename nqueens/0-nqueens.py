#!/usr/bin/python3
"""
N-QUEEN
"""

import sys

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)

if sys.argv[1].isdigit() is False:
    print("N must be a number")
    sys.exit(1)

N = int(sys.argv[1])

if N < 4:
    print("N must be at least 4")
    sys.exit(1)


def solve_nqueens(n):
    """Solves the N-Queens problem and prints solutions."""
    def is_safe(row, col, queens):
        """Check safety"""
        for r, c in enumerate(queens):
            if c == col or abs(c - col) == abs(r - row):
                return False
        return True

    def backtrack(row, queens):
        """Backtrack mechanism"""
        if row == n:
            print([[r, c] for r, c in enumerate(queens)])
            return

        for col in range(n):
            if is_safe(row, col, queens):
                backtrack(row + 1, queens + [col])

    backtrack(0, [])


solve_nqueens(N)
