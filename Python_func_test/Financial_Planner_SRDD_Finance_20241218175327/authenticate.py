def authenticate(self, password):
        self.authenticated = password == self.password
        return self.authenticated