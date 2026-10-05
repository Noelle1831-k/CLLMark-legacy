def decrypt_data(self, encrypted_data):
        try:
            print("Decrypting data...")
            decoded_data = self.cipher.decrypt(encrypted_data).decode()
            print(f"Data decrypted: {decoded_data}")
            return decoded_data
        except Exception as e:
            print(f"Error during decryption: {e}")
            return None