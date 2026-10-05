def sort_on_occurence(lst):
    from collections import defaultdict
    d = defaultdict(list)
    for k, v in lst:
        d[k].append(v)
    result = []
    for k, v in sorted(d.items()):
        result.append((k, *v, len(v)))
    return result