def max_length(list1):
    max_len_list = max(list1, key=len)
    return (len(max_len_list), max_len_list)