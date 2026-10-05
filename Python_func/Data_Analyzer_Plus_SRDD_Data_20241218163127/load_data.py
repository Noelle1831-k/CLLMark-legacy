def load_data(self, file_path, file_type):
        if file_type == 'csv':
            return self.data_loader.read_csv(file_path)
        elif file_type == 'excel':
            return self.data_loader.read_excel(file_path)
        else:
            raise ValueError("Unsupported file type")