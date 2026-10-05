def list_users(self):
        if not self.users:
            print("No users available.")
        else:
            for idx, user in enumerate(self.users, start=1):
                print(f"{idx}. {user['name']} - {user['role']}")