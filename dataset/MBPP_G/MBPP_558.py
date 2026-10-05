def digit_distance_nums(n1, n2):
    n1, n2 = (str(n1), str(n2))
    return sum((abs(int(a) - int(b)) for a, b in zip(n1, n2)))