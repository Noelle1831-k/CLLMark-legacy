def create_profile(self, bio, location):
        if not bio or not location:
            raise ValueError("Bio and location must be non-empty strings.")
        self.profile['bio'] = bio
        self.profile['location'] = location