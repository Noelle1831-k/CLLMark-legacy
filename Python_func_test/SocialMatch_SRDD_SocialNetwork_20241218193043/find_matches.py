def find_matches(self):
        '''
        Finds potential matches for a user.
        '''
        username = input("Enter your username: ")
        user = self.database.load_user(username)
        if not user:
            print("User not found.")
            return
        users = self.database.load_all_users()
        matches = [(other_user, user.calculate_compatibility(other_user, self.interest_graph)) for other_user in users if other_user.username != username]
        ranked_matches = self.rank_matches(matches)
        for match, score in ranked_matches:
            print(f"Match: {match.username}, Compatibility Score: {score}")