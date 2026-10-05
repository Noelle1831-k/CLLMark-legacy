def store_data(self, data):
        try:
            # Read existing data
            existing_data = self.retrieve_data()
            # Append new data
            existing_data.append(data)
            # Write back all data
            with open(self.data_file, 'w') as file:
                json.dump(existing_data, file, indent=4)
        except IOError as e:
            print(f"Error storing data: {e}")