def decrypt(self, ciphertext):
        return self.cipher.decrypt(ciphertext.encode()).decode()