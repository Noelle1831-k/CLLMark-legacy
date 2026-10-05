def register(self):
        username = input("Enter username: ")
        password = input("Enter password: ")
        new_user = user.User(username, password)
        self.users.append(new_user)
        print("Registration successful!")