def load_data(self, file_path):
        import pandas as pd
        try:
            self.data = pd.read_csv(file_path)
            print(f"Data loaded successfully from {file_path}")
        except FileNotFoundError:
            print(f"Error: The file {file_path} was not found.")
        except Exception as e:
            print(f"An error occurred while loading data: {e}")