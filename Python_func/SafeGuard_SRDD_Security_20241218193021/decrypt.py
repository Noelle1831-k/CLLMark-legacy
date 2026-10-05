def decrypt(self, encrypted_data):
        '''
        Decrypts the data using AES encryption.
        '''
        print("Decrypting data...")
        decrypted_data = self.cipher.decrypt(encrypted_data).decode()
        print(f"Data decrypted: {decrypted_data}")
        return decrypted_data