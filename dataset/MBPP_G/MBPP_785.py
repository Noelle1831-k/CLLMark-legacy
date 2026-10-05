def tuple_str_int(test_str):
    return tuple(map(int, test_str.strip('()').split(', ')))