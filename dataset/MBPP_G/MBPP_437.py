def remove_odd(str1):
    return ''.join([str1[i] for i in range(len(str1)) if i % 2 != 0])