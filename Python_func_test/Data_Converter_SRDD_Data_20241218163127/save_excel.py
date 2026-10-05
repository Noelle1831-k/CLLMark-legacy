def save_excel(self, data, file_path):
        data.to_excel(file_path, index=False)