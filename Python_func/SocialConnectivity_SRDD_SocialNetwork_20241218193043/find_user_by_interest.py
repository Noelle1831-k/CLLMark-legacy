def find_user_by_interest(self, interest):
        if not interest:
            raise ValueError("Interest must be a non-empty string.")
        return [user for user in self.users if interest in user.interests]