def _hash_password(self, password):
        return hashlib.sha256(password.encode()).hexdigest()