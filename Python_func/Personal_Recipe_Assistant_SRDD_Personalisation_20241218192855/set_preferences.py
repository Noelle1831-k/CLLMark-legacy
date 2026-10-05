def set_preferences(self):
        self.dietary_restrictions = self._parse_input("Enter your dietary restrictions (comma-separated): ")
        self.flavor_preferences = self._parse_input("Enter your flavor preferences (comma-separated): ")