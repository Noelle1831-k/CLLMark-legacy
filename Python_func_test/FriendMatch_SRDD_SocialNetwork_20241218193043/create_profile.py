def create_profile(self, name, interests, preferences):
        self.profiles[name] = {
            f'interests': interests,
            f'preferences': preferences
        }