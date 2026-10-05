def count_ways(n):
    if n % 2 != 0:
        return 0
    ways = [0] * (n + 1)
    ways[0] = 1
    ways[2] = 3
    for i in range(4, n + 1, 2):
        ways[i] = 4 * ways[i - 2] - ways[i - 4]
    return ways[n]