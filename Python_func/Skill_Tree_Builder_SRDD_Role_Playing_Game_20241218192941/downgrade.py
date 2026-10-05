def downgrade(self):
        '''
        Decreases the skill's level by one if it's greater than zero.
        '''
        if self.level > 0:
            self.level -= 1