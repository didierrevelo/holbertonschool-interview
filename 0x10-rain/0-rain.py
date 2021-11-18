#!/usr/bin/env python3


def rain(walls):
    """
    """
    if not walls or not isinstance(walls, list):
        return 0

    n = len(walls)
    if n == 1:
        return 0

    left = [0] * n
    right = [0] * n
    left[0] = walls[0]
    for i in range(1, n):
        left[i] = max(left[i - 1], walls[i])

    right[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right[i] = max(right[i + 1], walls[i])

    ans = 0
    for i in range(n):
        ans += min(left[i], right[i]) - walls[i]

    return ans
