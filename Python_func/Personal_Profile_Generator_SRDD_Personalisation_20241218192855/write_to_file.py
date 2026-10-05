def write_to_file(self, profile):
        try:
            data = self.read_from_file()
            data.append(profile)
            with open(self.file_name, "w") as file:
                json.dump(data, file, indent=4)
        except Exception as e:
            raise IOError(f"Error writing to file: {str(e)}")