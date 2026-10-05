def import_data(self):
        try:
            data = pd.read_excel(self.file_path)
            print("Data imported successfully.")
            return data
        except Exception as e:
            print(f"Error importing data: {e}")
            return None