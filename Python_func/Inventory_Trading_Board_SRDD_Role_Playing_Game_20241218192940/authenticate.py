def authenticate(self, password):
        return self.password == hashlib.sha256(password.encode()).hexdigest()