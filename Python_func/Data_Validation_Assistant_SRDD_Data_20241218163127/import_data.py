def import_data(self, file_path):
        if file_path.endswith('.csv'):
            return self.import_csv(file_path)
        elif file_path.endswith('.xlsx'):
            return self.import_excel(file_path)
        elif file_path.endswith('.json'):
            return self.import_json(file_path)
        else:
            raise ValueError("Unsupported file format")