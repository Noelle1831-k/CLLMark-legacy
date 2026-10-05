def jacobsthal_num(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return jacobsthal_num(n - 1) + 2 * jacobsthal_num(n - 2)