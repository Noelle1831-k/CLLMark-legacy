def next_level(self):
        '''
        Determine if the game should proceed to the next level.
        '''
        response = input("Proceed to next level? (y/n): ")
        return response.lower() == 'y'