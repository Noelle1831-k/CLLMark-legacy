def count_range_in_list(li, min, max):
    return len([x for x in li if min <= x <= max])