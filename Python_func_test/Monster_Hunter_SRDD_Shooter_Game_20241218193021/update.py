def update(self):
        '''
        Update the ability's cooldown and duration status.
        '''
        if self.remaining_cooldown > 0:
            self.remaining_cooldown -= 1
        if self.active_duration > 0:
            self.active_duration -= 1
            if self.active_duration == 0:
                self.deactivate()