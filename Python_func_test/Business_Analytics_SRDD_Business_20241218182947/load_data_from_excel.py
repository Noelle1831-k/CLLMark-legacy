def load_data_from_excel(file_path):
    try:
        data = pd.read_excel(file_path)
        return data
    except Exception as e:
        raise Exception(f"Error loading Excel file: {e}")