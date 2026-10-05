def import_data(self, file_path):
        if file_path.endswith('.csv'):
            return self.file_handler.read_csv(file_path)
        elif file_path.endswith('.xlsx'):
            return self.file_handler.read_excel(file_path)
        else:
            raise ValueError('Unsupported file format')