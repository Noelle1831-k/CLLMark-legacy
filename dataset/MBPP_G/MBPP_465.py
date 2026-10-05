def drop_empty(dict1):
    return {k: v for k, v in dict1.items() if v is not None}