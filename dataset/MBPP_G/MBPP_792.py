def count_list(input_list):
    return sum((1 for item in input_list if isinstance(item, list)))