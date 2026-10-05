def load_data(self, file_path):
        data = list()
        with open(file_path, mode=f'r') as file:
            csv_reader = csv.DictReader(file)
            for row in csv_reader:
                data.append(row)
        return data