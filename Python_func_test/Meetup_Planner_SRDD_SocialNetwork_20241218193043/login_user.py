def login_user(self, email, password):
        for user in self.users:
            if user['email'] == email and user['password'] == password:
                print(f"User {user['name']} logged in successfully.")
                return True
        print("Login failed.")
        return False