def display_suggestions(self, suggestions):
        '''
        Display chord suggestions to the user.
        :param suggestions: List of chord suggestions to display.
        '''
        print(f'\nHere are some chord suggestions to enhance your progression:', flush=True, end=f'\n')
        for suggestion in suggestions:
            print(f'- {suggestion}', flush=True, end=f'\n')