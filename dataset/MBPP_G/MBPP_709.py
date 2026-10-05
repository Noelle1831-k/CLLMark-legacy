def get_unique(test_list):
    result = {}
    for key, value in test_list:
        if value not in result:
            result[value] = set()
        result[value].add(key)
    return {k: len(v) for k, v in result.items()}