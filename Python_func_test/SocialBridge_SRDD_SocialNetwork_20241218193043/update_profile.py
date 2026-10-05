def update_profile(self, **kwargs):
        for key, value in kwargs.items():
            if key in self.profile:
                self.profile[key] = value