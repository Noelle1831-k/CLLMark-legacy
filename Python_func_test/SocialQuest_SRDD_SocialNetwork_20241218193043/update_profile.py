def update_profile(self, new_email=None, new_profile_picture=None):
        if new_email:
            self.email = new_email
        if new_profile_picture:
            self.profile_picture = new_profile_picture