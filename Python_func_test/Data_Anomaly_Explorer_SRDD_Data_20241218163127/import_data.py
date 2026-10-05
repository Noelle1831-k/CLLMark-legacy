def import_data(self, file_path):
        try:
            self.data = pd.read_csv(file_path)
            print("Data imported successfully.")
        except Exception as e:
            print(f"Error importing data: {e}")