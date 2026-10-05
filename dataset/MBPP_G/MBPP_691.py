def group_element(test_list):
    result = {}
    for first, second in test_list:
        if second not in result:
            result[second] = []
        result[second].append(first)
    return result