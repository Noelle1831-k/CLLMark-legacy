def find_matches(self):
        user_id = int(input("Enter your User ID to find matches: "))
        matches = self.match_algo.suggest_matches(user_id)
        if not matches:
            print("No matches found.")
        else:
            print("Matches found:")
            for match_id, score in matches:
                match_user = self.db.get_user_by_id(match_id)
                print(f"{match_user.name} (Match Score: {score:.2f})")