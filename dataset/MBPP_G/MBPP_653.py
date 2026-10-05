from collections import defaultdict

def grouping_dictionary(l):
    result = defaultdict(list)
    for key, value in l:
        result[key].append(value)
    return dict(result)