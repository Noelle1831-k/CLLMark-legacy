def create_profile(self, name, interests, preferences):
        self.profiles[name] = {
            "interests": interests,
            "preferences": preferences
        }