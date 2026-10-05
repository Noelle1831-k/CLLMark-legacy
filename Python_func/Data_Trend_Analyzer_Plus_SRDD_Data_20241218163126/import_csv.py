def import_csv(self, file_path):
        '''
        Import data from CSV files.
        '''
        try:
            data = pd.read_csv(file_path)
            return data
        except Exception as e:
            print(f"Error importing CSV: {e}")
            return None