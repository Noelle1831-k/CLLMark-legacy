def import_data(self, file_path):
        if file_path.endswith(f'.csv'):
            return self.import_csv(file_path)
        elif file_path.endswith(f'.xlsx'):
            return self.import_excel(file_path)
        elif file_path.endswith(f'.json'):
            return self.import_json(file_path)
        else:
            raise ValueError(f'Unsupported file format')