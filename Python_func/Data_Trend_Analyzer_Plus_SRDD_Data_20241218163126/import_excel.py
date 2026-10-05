def import_excel(self, file_path):
        '''
        Import data from Excel files.
        '''
        try:
            data = pd.read_excel(file_path)
            return data
        except Exception as e:
            print(f"Error importing Excel: {e}")
            return None