def assign_elements(test_list):
    element_dict = {}
    for a, b in test_list:
        if a not in element_dict:
            element_dict[a] = []
        if b not in element_dict:
            element_dict[b] = []
        element_dict[a].append(b)
    return element_dict