def get_input(self):
        '''
        Captures the letters from the user.
        This method ensures that the input is valid, consisting only of alphabetic characters.
        :return: The string of letters input by the user, or None if the input is invalid.
        '''
        while True:
            letters = input("Enter a set of letters (without spaces): ").strip().lower()
            if not letters.isalpha():
                print("Invalid input. Please enter only alphabetic characters without spaces.")
                continue
            return letters