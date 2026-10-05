def encrypt(self, plaintext):
        return self.cipher.encrypt(plaintext.encode()).decode()