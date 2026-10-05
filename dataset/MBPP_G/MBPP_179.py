def is_num_keith(x):
    x_str = str(x)
    n_digits = len(x_str)
    digits = [int(d) for d in x_str]
    while True:
        next_term = sum(digits)
        if next_term == x:
            return True
        elif next_term > x:
            return False
        digits.pop(0)
        digits.append(next_term)