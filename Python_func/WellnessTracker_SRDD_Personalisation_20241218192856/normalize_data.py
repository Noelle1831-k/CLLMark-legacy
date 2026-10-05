def normalize_data(data):
    normalized_data = {}
    for key, value in data.items():
        normalized_data[key] = value / 10  # Simple normalization example
    return normalized_data