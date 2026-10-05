def decrypt_data(self, encrypted_data):
        decrypted_data = self.cipher.decrypt(encrypted_data).decode()
        print(f"Data decrypted: {decrypted_data}")
        return decrypted_data