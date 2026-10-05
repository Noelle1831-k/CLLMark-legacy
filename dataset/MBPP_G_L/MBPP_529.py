def jacobsthal_lucas(n):
    if n == 0:
        return 2
    elif n == 1:
        return 1
    else:
        jacobs_lucas_2 = 2
        jacobs_lucas_1 = 1
        for _ in range(2, n + 1):
            jacobs_lucas = jacobs_lucas_1 + 2 * jacobs_lucas_2
            jacobs_lucas_2 = jacobs_lucas_1
            jacobs_lucas_1 = jacobs_lucas
        return jacobs_lucas