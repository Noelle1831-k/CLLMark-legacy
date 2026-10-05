def select_rifle(self):
        '''
        Allows the player to select a rifle based on mission requirements.
        '''
        print('Selecting rifle...')
        for idx, rifle in enumerate(self.rifles, start=1):
            print(f'{idx}. {rifle["name"]} - Caliber: {rifle["caliber"]}, Range: {rifle["range"]}m, Stability: {rifle["stability"]}')
        choice = int(input('Select a rifle by number: ')) - 1
        if 0 <= choice < len(self.rifles):
            self.current_rifle = self.rifles[choice]
            print(f'Selected Rifle: {self.current_rifle["name"]}')
        else:
            print('Invalid choice, defaulting to first rifle.')
            self.current_rifle = self.rifles[0]