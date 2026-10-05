def modify_preferences(self):
        '''
        Allows the user to modify their preferences.
        '''
        print("\nCurrent Preferences:")
        for key, value in self.preferences.items():
            print(f"{key.replace('_', ' ').title()}: {value}")
        for key in self.preferences.keys():
            new_value = input(f"Enter new value for {key.replace('_', ' ').title()} (or press Enter to keep {self.preferences[key]}): ")
            if new_value:
                self.preferences[key] = new_value
        print("Preferences updated.")