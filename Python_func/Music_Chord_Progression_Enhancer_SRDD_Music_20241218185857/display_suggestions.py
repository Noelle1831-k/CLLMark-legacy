def display_suggestions(self, suggestions):
        '''
        Display chord suggestions to the user.
        :param suggestions: List of chord suggestions to display.
        '''
        print("\nHere are some chord suggestions to enhance your progression:")
        for suggestion in suggestions:
            print(f"- {suggestion}")