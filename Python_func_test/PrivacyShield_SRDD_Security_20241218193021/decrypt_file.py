def decrypt_file(self, file_path, key):
        '''
        Decrypt the specified file using the provided key.
        '''
        try:
            with open(file_path, 'rb') as file:
                encrypted_data = file.read()
            fernet = Fernet(key)
            data = fernet.decrypt(encrypted_data)
            with open(file_path, 'wb') as file:
                file.write(data)
            print(f"File {file_path} decrypted successfully.")
        except Exception as e:
            print(f"Failed to decrypt file {file_path}: {str(e)}")