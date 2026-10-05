def clear_screen(self):
        '''
        Clears the console screen for a better user experience.
        '''
        os.system('cls' if os.name == 'nt' else 'clear')