def read_excel(self, file_path):
        try:
            data = pd.read_excel(file_path)
            print("Excel data loaded successfully.")
            return data
        except Exception as e:
            print(f"Error loading Excel: {e}")