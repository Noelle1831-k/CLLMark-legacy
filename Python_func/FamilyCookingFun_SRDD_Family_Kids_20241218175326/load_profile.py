def load_profile(self, user_name):
        user = self.get_user(user_name)
        if user:
            logging.info(f"Loaded profile for user: {user_name}")
            return user
        logging.warning(f"User profile not found: {user_name}")
        return None