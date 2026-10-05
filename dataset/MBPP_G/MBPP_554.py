def Split(lst):
    return [num for num in lst if isinstance(num, int) and num % 2 != 0]