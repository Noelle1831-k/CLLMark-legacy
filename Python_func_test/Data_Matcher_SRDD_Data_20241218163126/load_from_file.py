def load_from_file(self, file_name):
        with open(file_name, 'r') as csvfile:
            reader = csv.reader(csvfile)
            headers = next(reader)
            for row in reader:
                self.records.append(Record(dict(zip(headers, row))))