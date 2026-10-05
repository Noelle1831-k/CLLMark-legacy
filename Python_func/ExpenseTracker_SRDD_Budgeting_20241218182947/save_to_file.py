def save_to_file(self, expenses, filename):
        try:
            with open(filename, 'w') as file:
                json.dump(expenses, file, indent=4)
        except IOError as e:
            print(f"Error: Unable to write to file '{filename}'. {e}")