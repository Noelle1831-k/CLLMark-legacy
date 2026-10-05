def sort_list(test_list):
    return sorted(test_list, key=lambda x: sum((len(str(num)) for num in x)))