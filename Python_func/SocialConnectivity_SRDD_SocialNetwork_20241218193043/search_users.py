def search_users(self, users, interest):
        if not interest:
            raise ValueError("Interest must be a non-empty string.")
        return [user for user in users if interest in user.interests]