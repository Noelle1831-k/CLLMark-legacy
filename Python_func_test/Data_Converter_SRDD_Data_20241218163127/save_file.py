def save_file(self, file_path):
        if file_path.endswith(f'.csv'):
            self.data_saver.save_csv(self.data, file_path)
        elif file_path.endswith(f'.xlsx'):
            self.data_saver.save_excel(self.data, file_path)
        elif file_path.endswith(f'.json'):
            self.data_saver.save_json(self.data, file_path)
        elif file_path.endswith(f'.xml'):
            self.data_saver.save_xml(self.data, file_path)
        else:
            self.utils.log(f'Unsupported file format')
            sys.exit(1)