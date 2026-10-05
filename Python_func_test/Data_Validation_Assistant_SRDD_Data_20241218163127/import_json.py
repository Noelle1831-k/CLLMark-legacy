def import_json(self, file_path):
        with open(file_path, 'r') as file:
            return pd.DataFrame(json.load(file))