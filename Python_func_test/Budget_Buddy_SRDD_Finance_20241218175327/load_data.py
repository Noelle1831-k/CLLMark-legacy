def load_data(self):
        try:
            with open(self.data_file, 'r') as file:
                data = json.load(file)
                self.user.load_from_dict(data)
        except FileNotFoundError:
            print('No previous data found. Starting fresh.')