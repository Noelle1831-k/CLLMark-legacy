def load_data_from_csv(file_path):
    try:
        data = pd.read_csv(file_path)
        return data
    except Exception as e:
        raise Exception(f"Error loading CSV file: {e}")