def set_preferences(self):
        self.dietary_restrictions = self._parse_input(f"Enter your dietary restrictions (comma-separated): ")
        self.flavor_preferences = self._parse_input(f"Enter your flavor preferences (comma-separated): ")