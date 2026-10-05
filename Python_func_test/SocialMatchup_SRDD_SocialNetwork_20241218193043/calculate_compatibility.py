def calculate_compatibility(self, user1, user2):
        skill_match = len(set(user1.skills) & set(user2.skills))
        interest_match = len(set(user1.interests) & set(user2.interests))
        return skill_match + interest_match