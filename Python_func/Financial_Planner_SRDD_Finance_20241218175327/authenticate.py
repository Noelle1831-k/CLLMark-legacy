def authenticate(self, password):
        self.authenticated = self.password == password
        return self.authenticated