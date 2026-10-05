def create_user(self, name, email):
        '''
        Creates a new user and adds it to the user dictionary.
        Parameters:
        - name (str): The name of the user.
        - email (str): The email address of the user.
        Returns:
        - str: The unique ID of the created user.
        Raises:
        - ValueError: If the email address is invalid.
        '''
        if not validate_email(email):
            raise ValueError("Invalid email address")
        user_id = generate_id()
        user = User(user_id, name, email)
        self.users[user_id] = user
        return user_id