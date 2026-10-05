def save_csv(self, data, file_path):
        data.to_csv(file_path, index=False)