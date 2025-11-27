#!/usr/bin/python3
"""
0-rain
"""


def rain(walls):
    """Calculate how many square units of water will be retained."""
    if not walls:
        return 0

    n = len(walls)
    water = 0

    for i in range(n):
        left_max = max(walls[:i+1])

        right_max = max(walls[i:])

        water += min(left_max, right_max) - walls[i]

    return water
