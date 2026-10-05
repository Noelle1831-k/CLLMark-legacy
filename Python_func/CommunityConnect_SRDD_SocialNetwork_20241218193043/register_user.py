def register_user(self, username, location):
        user = User(username, location)
        self.users.append(user)
        self.location_service.add_user(user)
        return user