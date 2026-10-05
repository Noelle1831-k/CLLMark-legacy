def max_aggregate(stdata):
    aggregates = {}
    for name, score in stdata:
        if name in aggregates:
            aggregates[name] += score
        else:
            aggregates[name] = score
    return max(aggregates.items(), key=lambda x: x[1])