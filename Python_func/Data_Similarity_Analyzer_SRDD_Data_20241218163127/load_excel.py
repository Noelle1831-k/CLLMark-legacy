def load_excel(self, file_path):
        '''
        Load dataset from an Excel file.
        '''
        try:
            data = pd.read_excel(file_path)
            return data
        except Exception as e:
            print(f"Error loading Excel file: {e}")
            return None