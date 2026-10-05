def load_csv(self, file_path):
        '''
        Load dataset from a CSV file.
        '''
        try:
            data = pd.read_csv(file_path)
            return data
        except Exception as e:
            print(f"Error loading CSV file: {e}")
            return None