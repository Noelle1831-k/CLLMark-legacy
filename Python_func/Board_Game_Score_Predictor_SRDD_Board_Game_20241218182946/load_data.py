def load_data(self, file_path):
        '''
        Load game data from a CSV file.
        '''
        try:
            data = pd.read_csv(file_path)
        except FileNotFoundError:
            raise Exception(f"The file at {file_path} was not found.")
        except pd.errors.EmptyDataError:
            raise Exception("The file is empty.")
        except pd.errors.ParserError:
            raise Exception("Error parsing the file.")
        return data