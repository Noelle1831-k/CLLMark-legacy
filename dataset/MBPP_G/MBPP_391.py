def convert_list_dictionary(l1, l2, l3):
    return [{k: {v: s}} for k, v, s in zip(l1, l2, l3)]