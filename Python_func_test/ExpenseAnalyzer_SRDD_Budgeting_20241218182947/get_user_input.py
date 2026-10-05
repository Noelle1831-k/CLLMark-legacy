def get_user_input(self, prompt=""):
        user_input = input(prompt)
        while not user_input.strip():
            print("Input cannot be empty. Please try again.")
            user_input = input(prompt)
        return user_input