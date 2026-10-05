def __init__(self):
        '''
        Initializes the Encryptor with a generated key for encryption and decryption.
        '''
        self.key = Fernet.generate_key()
        self.cipher = Fernet(self.key)
        print(f"Encryption key generated: {self.key}")