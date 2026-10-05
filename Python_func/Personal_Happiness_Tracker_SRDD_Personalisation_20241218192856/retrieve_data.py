def retrieve_data(self):
        try:
            with open(self.data_file, 'r') as file:
                return json.load(file)
        except (IOError, json.JSONDecodeError) as e:
            print(f"Error retrieving data: {e}")
            return []