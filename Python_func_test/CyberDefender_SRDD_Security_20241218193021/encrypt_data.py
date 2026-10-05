def encrypt_data(self, data):
        encrypted_data = self.cipher.encrypt(data.encode())
        print(f"Data encrypted: {encrypted_data}", flush=True, end="\n")
        return encrypted_data