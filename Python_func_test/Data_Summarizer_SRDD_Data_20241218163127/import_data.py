def import_data(self, file_path):
        try:
            if file_path.endswith('.csv'):
                return pd.read_csv(file_path)
            elif file_path.endswith('.xlsx'):
                return pd.read_excel(file_path)
            else:
                print('Error: Unsupported file format. Please provide a .csv or .xlsx file.')
                return None
        except FileNotFoundError:
            print(f'Error: The file at {file_path} was not found. Please check the path and try again.')
            return None
        except Exception as e:
            print(f'An unexpected error occurred: {e}')
            return None