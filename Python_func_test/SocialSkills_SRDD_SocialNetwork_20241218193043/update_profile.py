def update_profile(self, username):
        if username in self.users:
            new_goal = input("Enter new goal: ")
            self.users[username]['goals'].append(new_goal)
            print(f"Goal added for {username}.")
        else:
            print("User not found.")