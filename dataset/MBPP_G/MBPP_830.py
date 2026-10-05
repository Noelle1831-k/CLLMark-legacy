def round_up(a, digits):
    factor = 10 ** digits
    return int(a * factor + 0.9999999999) / factor