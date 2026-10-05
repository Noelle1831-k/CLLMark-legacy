def encrypt_file(self, file_path, key):
        '''
        Encrypt the specified file using the provided key.
        '''
        try:
            with open(file_path, 'rb') as file:
                data = file.read()
            fernet = Fernet(key)
            encrypted_data = fernet.encrypt(data)
            with open(file_path, 'wb') as file:
                file.write(encrypted_data)
            print(f"File {file_path} encrypted successfully.")
        except Exception as e:
            print(f"Failed to encrypt file {file_path}: {str(e)}")