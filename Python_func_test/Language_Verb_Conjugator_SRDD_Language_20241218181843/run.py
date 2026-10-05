def run(self):
        '''
        Runs the user interface.
        '''
        while True:
            user_input = input("Enter a verb to conjugate (or 'exit' to quit): ")
            if user_input.lower() == 'exit':
                break
            self.search_verb(user_input)