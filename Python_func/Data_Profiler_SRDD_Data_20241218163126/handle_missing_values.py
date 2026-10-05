def handle_missing_values(data):
    return data.fillna(data.mean())