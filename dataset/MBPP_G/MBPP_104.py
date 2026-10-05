def sort_sublists(input_list):
    return [sorted(sublist, key=lambda s: s.strip()) for sublist in input_list]