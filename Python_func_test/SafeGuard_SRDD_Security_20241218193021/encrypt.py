def encrypt(self, data):
        '''
        Encrypts the data using AES encryption.
        '''
        print('Encrypting data...')
        encrypted_data = self.cipher.encrypt(data.encode())
        print(f'Data encrypted: {encrypted_data}')
        return encrypted_data