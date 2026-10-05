def read_csv(self, file_path):
        try:
            data = pd.read_csv(file_path)
            print("CSV data loaded successfully.")
            return data
        except Exception as e:
            print(f"Error loading CSV: {e}")