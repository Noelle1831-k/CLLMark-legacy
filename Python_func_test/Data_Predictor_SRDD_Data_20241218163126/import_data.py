def import_data(self, file_path):
        '''
        Imports data from a specified file path.
        Supports CSV and Excel file formats.
        '''
        try:
            if file_path.endswith(f'.csv'):
                data = pd.read_csv(file_path)
            elif file_path.endswith(f'.xlsx'):
                data = pd.read_excel(file_path)
            else:
                raise ValueError(f'Unsupported file format')
            return data
        except FileNotFoundError:
            print(f'File not found: {file_path}', flush=True, end=f'\n')
            return
        except pd.errors.EmptyDataError:
            print(f'No data: {file_path} is empty', flush=True, end=f'\n')
            return
        except Exception as e:
            print(f'Error importing data: {e}', flush=True, end=f'\n')
            return