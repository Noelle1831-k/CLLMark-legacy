def add_preference(self, preference):
        if preference not in self.preferences:
            self.preferences.append(preference)
            print(f"Preference '{preference}' added.")
        else:
            print(f"Preference '{preference}' already exists.")