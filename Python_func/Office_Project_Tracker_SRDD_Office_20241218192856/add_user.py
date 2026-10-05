def add_user(self):
        user_name = input("Enter user name: ")
        user_role = input("Enter user role: ")
        user = {
            'name': user_name,
            'role': user_role
        }
        self.users.append(user)
        print(f"User '{user_name}' added successfully.")