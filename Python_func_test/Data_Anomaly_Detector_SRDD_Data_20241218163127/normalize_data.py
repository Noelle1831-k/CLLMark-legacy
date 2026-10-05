def normalize_data(data):
    try:
        normalized_data = (data - data.min()) / (data.max() - data.min())
        print("Data normalized successfully.")
        return normalized_data
    except Exception as e:
        print(f"Error normalizing data: {e}")
        return data