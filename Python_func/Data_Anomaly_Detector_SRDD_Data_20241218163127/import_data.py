def import_data(self, file_path):
        try:
            self.data = pd.read_csv(file_path)
            print(f"Data successfully imported from {file_path}")
        except Exception as e:
            print(f"Error importing data: {e}")
        return self.data