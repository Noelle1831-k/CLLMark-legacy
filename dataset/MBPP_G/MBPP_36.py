def find_Nth_Digit(p, q, N):
    result = p / q
    fraction_str = str(result)[2:]
    if N > len(fraction_str):
        return None
    return int(fraction_str[N - 1])