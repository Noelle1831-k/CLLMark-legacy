def check_occurences(test_list):
    result = {}
    for a, b in test_list:
        pair = tuple(sorted((a, b)))
        result[pair] = result.get(pair, 0) + 1
    return {k: v for k, v in result.items()}