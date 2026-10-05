def load_from_file(self, filename):
        '''
        Load data from a file in JSON format.
        '''
        try:
            with open(filename, 'r') as file:
                return json.load(file)
        except FileNotFoundError:
            print(f"File {filename} not found. Returning empty data.")
            return {"incomes": [], "expenses": []}
        except json.JSONDecodeError as e:
            print(f"An error occurred while decoding JSON from file: {e}")
            return {"incomes": [], "expenses": []}
        except IOError as e:
            print(f"An error occurred while loading from file: {e}")
            return {"incomes": [], "expenses": []}