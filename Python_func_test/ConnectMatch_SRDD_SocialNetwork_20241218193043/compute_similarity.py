def compute_similarity(self, user1, user2):
        attributes1 = set(user1.skills + user1.expertise + user1.interests)
        attributes2 = set(user2.skills + user2.expertise + user2.interests)
        intersection = len(attributes1.intersection(attributes2))
        union = len(attributes1.union(attributes2))
        return intersection / union if union != 0 else 0