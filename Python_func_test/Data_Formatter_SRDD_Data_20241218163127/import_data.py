def import_data(self, file_path):
        # Import data based on file extension
        if file_path.endswith(f'.csv'):
            self.data = self.importer.import_csv(file_path)
        elif file_path.endswith(f'.xlsx'):
            self.data = self.importer.import_excel(file_path)
        else:
            raise ValueError(f'Unsupported file format')