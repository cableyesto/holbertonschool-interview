#!/usr/bin/python3
"""
0-prime_game module
Determines the winner of a prime game between Maria and Ben.
"""


def isWinner(x, nums):
    """
    Determines who wins the most rounds of the Prime Game.

    Maria and Ben play x rounds. In each round, given a set of integers
    from 1 to n, players pick prime numbers and remove multiples. The
    player who cannot pick a prime loses that round.

    Args:
        x (int): Number of rounds.
        nums (list): List of n values for each round.

    Returns:
        str or None: Name of the player with most wins ("Maria" or "Ben").
                     Returns None if there is a tie or input is invalid.
    """
    if not nums or x < 1:
        return None

    # Find maximum n to generate primes efficiently
    max_n = max(nums)

    # Sieve of Eratosthenes to find all primes <= max_n
    sieve = [True] * (max_n + 1)
    sieve[0] = sieve[1] = False

    for i in range(2, int(max_n ** 0.5) + 1):
        if sieve[i]:
            for j in range(i * i, max_n + 1, i):
                sieve[j] = False

    # Precompute number of prime moves for each number <= max_n
    prime_count = [0] * (max_n + 1)
    count = 0
    for i in range(2, max_n + 1):
        if sieve[i]:
            count += 1
        prime_count[i] = count

    # Play the game for each round
    maria_wins = 0
    ben_wins = 0
    for n in nums:
        if prime_count[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    return None
