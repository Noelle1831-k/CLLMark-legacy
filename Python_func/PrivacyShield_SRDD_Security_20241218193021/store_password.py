def store_password(self, account, password):
        '''
        Store the password for the specified account.
        '''
        try:
            with open('passwords.txt', 'a') as file:
                file.write(f"{account}: {password}\n")
            print(f"Password for {account} stored successfully.")
        except Exception as e:
            print(f"Failed to store password: {str(e)}")