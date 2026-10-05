def import_data(self, file_path):
        '''
        Imports data from a specified file path.
        Supports CSV and Excel file formats.
        '''
        try:
            if file_path.endswith('.csv'):
                data = pd.read_csv(file_path)
            elif file_path.endswith('.xlsx'):
                data = pd.read_excel(file_path)
            else:
                raise ValueError('Unsupported file format')
            return data
        except FileNotFoundError:
            print(f"File not found: {file_path}")
            return None
        except pd.errors.EmptyDataError:
            print(f"No data: {file_path} is empty")
            return None
        except Exception as e:
            print(f"Error importing data: {e}")
            return None