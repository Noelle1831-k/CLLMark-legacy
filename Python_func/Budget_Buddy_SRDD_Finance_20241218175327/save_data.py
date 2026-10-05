def save_data(self):
        with open(self.data_file, 'w') as file:
            json.dump(self.user.to_dict(), file)