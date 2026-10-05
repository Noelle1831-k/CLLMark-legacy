def hit(self):
        '''
        Reduces the player's lives by one and checks if the game is over.
        '''
        self.lives -= 1
        if self.lives <= 0:
            return True
        return False