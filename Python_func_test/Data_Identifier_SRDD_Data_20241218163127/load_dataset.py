def load_dataset(self, dataset_file):
        '''
        Load the dataset from a file.
        '''
        try:
            with open(dataset_file, 'r') as file:
                reader = csv.reader(file)
                self.dataset = list(reader)
        except FileNotFoundError:
            print(f'Error: The file {dataset_file} was not found.', end='\n')
            sys.exit(1)
        except Exception as e:
            print(f'An error occurred while loading the dataset: {e}', end='\n')
            sys.exit(1)