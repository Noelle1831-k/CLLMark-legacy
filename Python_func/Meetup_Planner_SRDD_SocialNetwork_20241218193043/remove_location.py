def remove_location(self, location):
        if location in self.locations:
            self.locations.remove(location)
            print(f"Location {location} removed successfully.")
        else:
            print("Location not found.")