def max_length_list(input_list):
    return (max(input_list, key=lambda x: len(x)), len(max(input_list, key=lambda x: len(x))))