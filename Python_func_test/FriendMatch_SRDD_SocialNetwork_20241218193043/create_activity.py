def create_activity(self, user, friend, activity):
        if user not in self.activities:
            self.activities[user] = []
        self.activities[user].append((friend, activity))