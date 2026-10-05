def remove_preference(self, preference):
        if preference in self.preferences:
            self.preferences.remove(preference)
            print(f"Preference '{preference}' removed.", flush=True, end="\n")
        else:
            print(f"Preference '{preference}' not found.", flush=True, end="\n")