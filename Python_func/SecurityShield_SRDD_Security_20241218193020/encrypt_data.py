def encrypt_data(self, data):
        try:
            print("Encrypting data...")
            encoded_data = self.cipher.encrypt(data.encode())
            print(f"Data encrypted: {encoded_data}")
            return encoded_data
        except Exception as e:
            print(f"Error during encryption: {e}")
            return None