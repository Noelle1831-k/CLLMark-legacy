def update_entry(self, key, value):
        if key in self.data:
            self.data[key] = value
            print(f"Entry updated: {key}")
        else:
            print("Entry not found.")