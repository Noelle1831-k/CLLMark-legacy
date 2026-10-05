def write_file(self, file_path, data):
        data.to_csv(file_path, index=False)