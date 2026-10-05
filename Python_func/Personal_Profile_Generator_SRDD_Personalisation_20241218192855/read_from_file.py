def read_from_file(self):
        try:
            with open(self.file_name, "r") as file:
                return json.load(file)
        except FileNotFoundError:
            return []
        except json.JSONDecodeError:
            raise ValueError("Error decoding JSON data.")