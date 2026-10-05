def sort_dict_item(test_dict):
    return dict(sorted(test_dict.items(), key=lambda item: item[0][0] * item[0][1]))