def eulerian_num(n, m):
    if m >= n or n == 0:
        return 0
    elif m == 0:
        return 1
    else:
        return (n - m) * eulerian_num(n - 1, m - 1) + (m + 1) * eulerian_num(n - 1, m)