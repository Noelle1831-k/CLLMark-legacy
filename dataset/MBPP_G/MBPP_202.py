def remove_even(str1):
    return ''.join([char for i, char in enumerate(str1) if i % 2 == 0])