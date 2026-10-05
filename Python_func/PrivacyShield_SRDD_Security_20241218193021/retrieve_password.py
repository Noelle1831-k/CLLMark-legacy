def retrieve_password(self, account):
        '''
        Retrieve the password for the specified account.
        '''
        try:
            with open('passwords.txt', 'r') as file:
                for line in file:
                    acc, pwd = line.strip().split(': ')
                    if acc == account:
                        return pwd
            print(f"No password found for {account}.")
        except Exception as e:
            print(f"Failed to retrieve password: {str(e)}")