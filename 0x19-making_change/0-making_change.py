#!/usr/bin/python3

"""0. Change comes from within"""


def makeChange(coins, total):
    """Given a pile of coins of
    different values, determine
    the fewest number of coins
    needed to meet a given amount
    total."""
    if(total <= 0):
        return 0

    placeholder = total + 1

    memory = {0: 0}

    for i in range(1, total + 1):
        memory[i] = placeholder

        for coin in coins:
            current = i - coin
            if current < 0:
                continue

            memory[i] = min(memory[current] + 1, memory[i])

    if memory[total] == total + 1:
        return -1

    return memory[total]
