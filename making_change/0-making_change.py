#!/usr/bin/python3
"""
0-making_change.py

Determine the fewest number of coins needed to meet a given total.
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet total.

    Args:
        coins (list): list of coin denominations (positive integers)
        total (int): target total amount

    Returns:
        int: fewest number of coins needed to meet total
             - 0 if total is 0 or less
             - -1 if total cannot be met
    """
    if total <= 0:
        return 0

    if not coins:
        return -1

    # Initialize DP table
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for coin in coins:
        for amount in range(coin, total + 1):
            if dp[amount - coin] != float('inf'):
                dp[amount] = min(dp[amount],
                                 dp[amount - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
