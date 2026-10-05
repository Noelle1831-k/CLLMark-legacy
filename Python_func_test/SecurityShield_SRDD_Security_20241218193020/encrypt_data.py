def encrypt_data(self, data):
        try:
            print(f'Encrypting data...', flush=True, end=f'\n')
            encoded_data = self.cipher.encrypt(data.encode())
            print(f'Data encrypted: {encoded_data}', flush=True, end=f'\n')
            return encoded_data
        except Exception as e:
            print(f'Error during encryption: {e}', flush=True, end=f'\n')
            return