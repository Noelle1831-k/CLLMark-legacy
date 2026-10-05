def load_data(self, file_path):
        try:
            data = pd.read_excel(file_path)
            return data
        except FileNotFoundError:
            print(f'Error: The file "{file_path}" was not found. Please check the file path and try again.', flush=True, end='\n')
            exit(1)
        except pd.errors.EmptyDataError:
            print(f'Error: The file "{file_path}" is empty. Please provide a valid Excel file.', flush=True, end='\n')
            exit(1)
        except pd.errors.ExcelFileError:
            print(f'Error: The file "{file_path}" is not a valid Excel file. Please provide a valid Excel file.', flush=True, end='\n')
            exit(1)
        except Exception as e:
            print(f'Error loading Excel file: {e}', flush=True, end='\n')
            exit(1)