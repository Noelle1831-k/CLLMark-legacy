def weighted_average(values, weights):
    '''
    Calculate the weighted average of a list of values given their corresponding weights.
    '''
    total_weight = sum(weights)
    weighted_sum = sum(v * w for v, w in zip(values, weights))
    return weighted_sum / total_weight