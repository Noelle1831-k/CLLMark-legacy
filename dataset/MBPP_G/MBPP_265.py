def list_split(S, step):
    result = [[] for _ in range(step)]
    for i, item in enumerate(S):
        result[i % step].append(item)
    return result