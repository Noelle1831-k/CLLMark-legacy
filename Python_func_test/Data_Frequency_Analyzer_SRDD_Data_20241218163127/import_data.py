def import_data(self):
        try:
            data = pd.read_excel(self.file_path)
            print("Data imported successfully.", flush=True)
            return data
        except Exception as e:
            print(f"Error importing data: {e}", flush=True)
            return None