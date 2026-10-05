def handle_generate_password(self):
        length = int(input("Enter desired password length: "))
        password = self.password_manager.generate_password(length)
        print(f"Generated password: {password}")