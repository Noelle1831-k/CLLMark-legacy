def _has_common_interests(self, user1, user2):
        return bool(set(user1.interests) & set(user2.interests))