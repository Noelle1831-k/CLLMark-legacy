def create_profile(self, user_name):
        user = UserProfile(user_name)
        self.users.append(user)
        logging.info(f"Created profile for user: {user_name}")