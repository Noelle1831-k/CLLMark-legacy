def update_multiplier(self):
        '''
        Updates the score multiplier based on the current combo counter.
        The multiplier increases with consecutive successful drifts.
        '''
        if self.combo_counter > 5:
            self.multiplier = 1.5
        elif self.combo_counter > 10:
            self.multiplier = 2.0
        elif self.combo_counter > 20:
            self.multiplier = 3.0
        else:
            self.multiplier = 1.0