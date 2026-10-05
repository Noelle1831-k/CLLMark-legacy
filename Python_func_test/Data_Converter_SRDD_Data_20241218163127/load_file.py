def load_file(self, file_path):
        if file_path.endswith('.csv'):
            self.data = self.data_loader.load_csv(file_path)
        elif file_path.endswith('.xlsx'):
            self.data = self.data_loader.load_excel(file_path)
        elif file_path.endswith('.json'):
            self.data = self.data_loader.load_json(file_path)
        elif file_path.endswith('.xml'):
            self.data = self.data_loader.load_xml(file_path)
        else:
            self.utils.log('Unsupported file format')
            sys.exit(1)