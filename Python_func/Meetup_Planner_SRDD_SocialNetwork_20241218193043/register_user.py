def register_user(self, name, email, password):
        user = {"name": name, "email": email, "password": password}
        self.users.append(user)
        print(f"User {name} registered successfully.")