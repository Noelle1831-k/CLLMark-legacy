def dict_filter(dict, n):
    return {key: value for key, value in dict.items() if value >= n}