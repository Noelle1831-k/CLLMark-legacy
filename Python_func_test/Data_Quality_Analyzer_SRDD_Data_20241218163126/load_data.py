def load_data(self, file_path):
        '''
        Load data from a CSV file.
        '''
        data = []
        try:
            with open(file_path, mode='r') as file:
                csv_reader = csv.DictReader(file)
                for row in csv_reader:
                    data.append(row)
        except FileNotFoundError:
            print(f"File {file_path} not found.", flush=True)
        return data