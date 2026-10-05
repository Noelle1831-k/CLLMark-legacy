def update_profile(self, name, interests=None, preferences=None):
        if name in self.profiles:
            if interests:
                self.profiles[name][f"interests"] = interests
            if preferences:
                self.profiles[name][f"preferences"] = preferences