def remove_datatype(test_tuple, data_type):
    return [item for item in test_tuple if not isinstance(item, data_type)]