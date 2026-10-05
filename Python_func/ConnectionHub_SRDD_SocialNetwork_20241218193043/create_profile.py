def create_profile(self, name, title, email):
        if email not in self.profiles:
            self.profiles[email] = {"name": name, "title": title}
            print(f"Profile created for {name}.")
        else:
            print("Profile already exists.")