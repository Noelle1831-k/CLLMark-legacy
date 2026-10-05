def save_data(self, data):
        try:
            with open(self.file_path, 'w') as file:
                json.dump(data, file)
        except IOError:
            raise IOError("Failed to save data. Please check file permissions.")