def create_profile(self, name, email, password):
        if email in self.users:
            raise ValueError("User already exists.")
        self.users[email] = {"name": name, "password": password, "bio": ""}
        print(f"Profile created for {name}.")