def validate_data(self, data):
        for entry in data:
            if 'source' not in entry or 'amount' not in entry or 'date' not in entry:
                raise ValueError("Invalid data entry: {}".format(entry))