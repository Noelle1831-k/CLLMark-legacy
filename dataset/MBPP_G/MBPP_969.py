def join_tuples(test_list):
    result = []
    temp_dict = {}
    for tpl in test_list:
        if tpl[0] not in temp_dict:
            temp_dict[tpl[0]] = list(tpl)
        else:
            temp_dict[tpl[0]].extend(tpl[1:])
    for key, val in temp_dict.items():
        result.append(tuple(val))
    return result