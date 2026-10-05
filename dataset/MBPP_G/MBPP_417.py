def group_tuples(Input):
    from collections import defaultdict
    d = defaultdict(list)
    for a, b in Input:
        d[a].append(b)
    return [tuple([k] + v) for k, v in d.items()]