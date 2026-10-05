def tuple_int_str(tuple_str):
    return tuple((tuple((int(num) for num in sub_tuple)) for sub_tuple in tuple_str))