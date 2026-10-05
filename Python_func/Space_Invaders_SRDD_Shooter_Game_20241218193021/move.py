def move(self):
        '''
        Moves the alien down the screen, resetting position if it goes off screen.
        '''
        self.y += self.speed
        if self.y > self.screen.get_height():
            self.y = -self.height