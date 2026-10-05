def gain_points(self, points):
        '''
        Increases the user's points and checks for level-up.
        '''
        self.points += points
        self.level_up()