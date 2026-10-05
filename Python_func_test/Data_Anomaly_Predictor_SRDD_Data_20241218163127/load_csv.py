def load_csv(file_path):
    try:
        data = pd.read_csv(file_path)
        return data
    except FileNotFoundError:
        raise Exception("File not found. Please check the file path.")