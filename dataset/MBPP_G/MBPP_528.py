def min_length(list1):
    min_list = min(list1, key=len)
    return (len(min_list), min_list)