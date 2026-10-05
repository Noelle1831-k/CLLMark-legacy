def display_all_users(self):
        users = self.db.get_all_users()
        if not users:
            print("No users in the database.")
        else:
            print("All Users:")
            for user in users:
                print(f"ID: {user.user_id}, Name: {user.name}")