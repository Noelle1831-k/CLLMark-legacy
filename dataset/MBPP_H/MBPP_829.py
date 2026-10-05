def second_frequent(input):
    from collections import Counter
    dict = Counter(input)
    value = sorted(set(dict.values()), reverse=True)
    if len(value) < 2:
        return None
    second_large = value[1]
    for (key, val) in dict.items():
        if val == second_large:
            return (key)