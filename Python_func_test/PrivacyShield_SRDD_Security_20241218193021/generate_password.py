def generate_password(self, length, complexity):
        '''
        Generate a strong password based on the specified length and complexity.
        '''
        try:
            if complexity == 1:
                chars = string.ascii_lowercase
            elif complexity == 2:
                chars = string.ascii_letters
            elif complexity == 3:
                chars = string.ascii_letters + string.digits + string.punctuation
            else:
                raise ValueError("Invalid complexity level.")
            password = ''.join(random.choice(chars) for _ in range(length))
            return password
        except Exception as e:
            print(f"Failed to generate password: {str(e)}")