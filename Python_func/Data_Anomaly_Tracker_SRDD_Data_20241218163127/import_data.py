def import_data(file_path, columns=None):
    try:
        if columns:
            data = pd.read_csv(file_path, usecols=columns)
        else:
            data = pd.read_csv(file_path)
        print(f"Data imported successfully with columns: {data.columns.tolist()}")
        return data
    except FileNotFoundError:
        print(f"Error: The file {file_path} was not found.")
        return None
    except ValueError as ve:
        print(f"Error: {ve}")
        return None
    except Exception as e:
        print(f"Error importing data: {e}")
        return None