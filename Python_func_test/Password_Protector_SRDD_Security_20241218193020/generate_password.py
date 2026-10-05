def generate_password(self, length=12):
        # Generate a random password with specified length
        characters = string.ascii_letters + string.digits + string.punctuation
        password = ''.join(random.choice(characters) for i in range(length))
        return password