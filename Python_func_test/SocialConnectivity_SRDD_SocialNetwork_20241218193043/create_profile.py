def create_profile(self, bio, location):
        if not bio or not location:
            raise ValueError(f'Bio and location must be non-empty strings.')
        self.profile[f'bio'] = bio
        self.profile[f'location'] = location