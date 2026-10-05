def create_profile(self, name, email):
        if email not in self.users:
            self.users[email] = {'name': name, 'profile': {}, 'connections': []}
            print(f"Profile created for {name}.")
        else:
            print("Email already exists.")