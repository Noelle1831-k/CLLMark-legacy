def format_data(data):
    print("Formatting data...")
    return {key: round(value, 2) for key, value in data.items()}