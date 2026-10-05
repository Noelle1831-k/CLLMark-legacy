def set_goals(self, username):
        if username in self.users:
            goals = self.users[username]['goals']
            print(f"{username}'s goals: {', '.join(goals)}")
        else:
            print("User not found.")