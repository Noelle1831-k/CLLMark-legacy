def set_dietary_preferences(self):
        print("Setting dietary preferences...")
        while True:
            preference = input("Enter a dietary preference (or 'done' to finish): ").strip().lower()
            if preference == 'done':
                break
            self.user_preferences.add_preference(preference)