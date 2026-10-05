def create_user(self):
        name = input("Enter your name: ")
        email = input("Enter your email: ")
        user_obj = user.User(name, email)
        self.users.append(user_obj)
        print(f"User {name} created successfully!")