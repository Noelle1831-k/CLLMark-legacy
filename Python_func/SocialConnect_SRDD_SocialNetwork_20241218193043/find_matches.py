def find_matches(self):
        matches = {}
        users = self.network.get_users()
        for i in range(len(users)):
            user1 = users[i]
            matches[user1] = []
            for j in range(i + 1, len(users)):
                user2 = users[j]
                score = self._calculate_match_score(user1, user2)
                if score > 0:
                    matches[user1].append((user2, score))
                    matches.setdefault(user2, []).append((user1, score))
        # Sort matches by score
        for user in matches:
            matches[user].sort(key=lambda x: x[1], reverse=True)
        return matches