def get_user_by_id(self, user_id):
        return self.user_profiles.get(user_id, None)