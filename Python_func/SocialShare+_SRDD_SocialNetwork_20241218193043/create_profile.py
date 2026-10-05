def create_profile(self, bio, profile_picture):
        self.profile.update_bio(bio)
        self.profile.update_profile_picture(profile_picture)