def register_user(self, username, password, profile_pic, bio):
        if self.database.find_user(username):
            raise ValueError(f"Username already exists")
        new_user = User(username, password, profile_pic, bio)
        self.database.add_user(new_user)
        return new_user