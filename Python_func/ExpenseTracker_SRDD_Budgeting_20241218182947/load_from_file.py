def load_from_file(self, filename):
        try:
            with open(filename, 'r') as file:
                return json.load(file)
        except FileNotFoundError:
            print(f"Warning: The file '{filename}' was not found. Starting with an empty expense list.")
            return []
        except json.JSONDecodeError:
            print(f"Error: The file '{filename}' contains invalid JSON. Starting with an empty expense list.")
            return []
        except IOError as e:
            print(f"Error: Unable to read from file '{filename}'. {e}")
            return []