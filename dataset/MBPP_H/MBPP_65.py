def recursive_list_sum(data_list):
    total = 0
    for element in data_list:
        if isinstance(element, list):
            total = total + recursive_list_sum(element)
        else:
            total = total + element
    return total