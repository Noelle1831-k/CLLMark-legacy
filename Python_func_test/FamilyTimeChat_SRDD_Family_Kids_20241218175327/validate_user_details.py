def validate_user_details(self):
        if not re.match(r'^[a-zA-Z0-9_]+$', self.username):
            raise ValueError('Username can only contain letters, numbers, and underscores.')
        if len(self.password) < 6:
            raise ValueError('Password must be at least 6 characters long.')
        if not re.match(r'[^@]+@[^@]+\.[^@]+', self.email):
            raise ValueError('Invalid email address.')