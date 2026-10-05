def register_user(self, username, email, password):
        if username not in self.users and validate_email(email):
            user = UserProfile(username, email)
            self.users[username] = {'profile': user, 'password': password}
            return user
        return None