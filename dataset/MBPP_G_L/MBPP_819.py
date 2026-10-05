def count_duplic(lists):
    if not lists:
        return ([], [])
    values = [lists[0]]
    counts = [1]
    for current in lists[1:]:
        if current == values[-1]:
            counts[-1] += 1
        else:
            values.append(current)
            counts.append(1)
    return (values, counts)