def float_sort(price):
    return sorted(price, key=lambda x: float(x[1]), reverse=True)