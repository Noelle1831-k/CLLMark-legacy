def min_Jumps(a, b, d):
    if d == 0:
        return 0
    jumps = d / a
    remainder = d % a
    if remainder == 0:
        return jumps
    if remainder <= b:
        return math.ceil(jumps + remainder / b)
    return jumps + remainder / b