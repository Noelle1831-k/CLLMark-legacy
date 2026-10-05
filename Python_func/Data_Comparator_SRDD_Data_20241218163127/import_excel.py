def import_excel(self, file_path):
        data = []
        try:
            data = pd.read_excel(file_path)
        except FileNotFoundError:
            print(f"Error: The file {file_path} was not found.")
        except Exception as e:
            print(f"An error occurred while importing Excel: {e}")
        return data.values.tolist()