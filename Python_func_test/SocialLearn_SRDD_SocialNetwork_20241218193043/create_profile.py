def create_profile(self, name, email, bio=f'', location=f''):
        self.profile = {
            f'name': name,
            f'email': email,
            f'bio': bio,
            f'location': location
        }