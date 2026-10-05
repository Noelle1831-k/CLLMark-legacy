def fill_missing_values(data):
    for i in range(len(data)):
        if data[i] is None:
            data[i] = 0  # Example strategy: fill with zero
    return data