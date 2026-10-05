def add_location(self, location):
        if location not in self.locations:
            self.locations.append(location)
            print(f"Location {location} added successfully.")
        else:
            print(f"Location {location} already exists.")