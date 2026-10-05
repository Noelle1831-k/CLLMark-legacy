def find_Index(n):
    num_digits = 0
    index = 0
    while num_digits < n:
        index += 1
        triangular_number = index * (index + 1) // 2
        num_digits = len(str(triangular_number))
    return index