def import_data(self, file_path):
        '''
        Imports data from the specified file path.
        '''
        try:
            data = pd.read_csv(file_path)
            return data
        except Exception as e:
            print(f'Error importing data: {e}', flush=True, end='\n')
            return