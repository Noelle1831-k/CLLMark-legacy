def suggest_matches(self, user_id):
        target_user = self.database.get_user_by_id(user_id)
        if not target_user:
            print(f"User with ID {user_id} not found.")
            return []
        similarity_scores = []
        for user in self.database.get_all_users():
            if user.user_id != user_id:
                similarity = self.compute_similarity(target_user, user)
                similarity_scores.append((user.user_id, similarity))
        similarity_scores.sort(key=lambda x: x[1], reverse=True)
        return similarity_scores[:5]  # Return top 5 matches