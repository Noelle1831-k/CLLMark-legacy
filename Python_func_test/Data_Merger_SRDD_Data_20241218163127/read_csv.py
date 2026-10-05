def read_csv(self, file_path):
        with open(file_path, mode='r') as file:
            reader = csv.DictReader(file)
            return [row for row in reader]