def draw(self):
        '''
        Draws the alien on the screen.
        '''
        pygame.draw.rect(self.screen, self.color, (self.x, self.y, self.width, self.height))