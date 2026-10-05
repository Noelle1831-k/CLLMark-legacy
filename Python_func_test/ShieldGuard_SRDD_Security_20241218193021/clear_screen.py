def clear_screen(self):
        '''Clear the console screen for better user experience.'''
        os.system('cls' if os.name == 'nt' else 'clear')