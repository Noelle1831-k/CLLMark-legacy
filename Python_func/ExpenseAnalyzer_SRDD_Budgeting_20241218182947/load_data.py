def load_data(self):
        try:
            with open(self.file_path, 'r') as file:
                data = json.load(file)
            return data
        except FileNotFoundError:
            raise FileNotFoundError("Data file not found. Please save data first.")
        except json.JSONDecodeError:
            raise ValueError("Failed to decode data. The file may be corrupted.")