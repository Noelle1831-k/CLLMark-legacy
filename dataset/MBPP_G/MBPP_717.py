def sd_calc(data):
    mean = sum(data) / len(data)
    var = sum(((x - mean) ** 2 for x in data)) / len(data)
    return var ** 0.5