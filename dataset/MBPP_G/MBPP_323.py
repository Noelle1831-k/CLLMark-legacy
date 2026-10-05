def re_arrange(arr, n):
    pos = [x for x in arr if x >= 0]
    neg = [x for x in arr if x < 0]
    result = []
    i, j = (0, 0)
    while i < len(pos) and j < len(neg):
        result.append(neg[j])
        result.append(pos[i])
        i += 1
        j += 1
    while j < len(neg):
        result.append(neg[j])
        j += 1
    while i < len(pos):
        result.append(pos[i])
        i += 1
    return result