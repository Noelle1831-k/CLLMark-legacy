def merge(lst):
    num_elements = len(lst[0])
    merged = [[] for _ in range(num_elements)]
    for sublist in lst:
        for i in range(num_elements):
            merged[i].append(sublist[i])
    return merged