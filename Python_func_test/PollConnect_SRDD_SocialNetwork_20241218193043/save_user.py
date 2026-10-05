def save_user(self, user_data):
        self.users[user_data["name"]] = user_data
        print(f"User {user_data['name']} saved to database.")