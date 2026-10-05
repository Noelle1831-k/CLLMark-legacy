def find_lists(Input):
    return sum((1 for item in Input if isinstance(item, list)))