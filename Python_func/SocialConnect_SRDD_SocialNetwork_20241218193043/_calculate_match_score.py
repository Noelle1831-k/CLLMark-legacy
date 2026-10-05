def _calculate_match_score(self, user1, user2):
        common_interests = set(user1.interests) & set(user2.interests)
        return len(common_interests)