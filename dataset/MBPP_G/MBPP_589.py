def perfect_squares(a, b):
    return [i * i for i in range(int(a ** 0.5), int(b ** 0.5) + 1) if a <= i * i <= b]