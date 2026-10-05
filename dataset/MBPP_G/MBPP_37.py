def sort_mixed_list(mixed_list):
    return sorted([x for x in mixed_list if isinstance(x, int)]) + sorted([x for x in mixed_list if isinstance(x, str)])