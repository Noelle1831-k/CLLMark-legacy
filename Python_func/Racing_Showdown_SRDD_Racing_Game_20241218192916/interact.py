def interact(self, vehicle):
        '''
        Interact with a vehicle, applying the obstacle's effect.
        :param vehicle: The vehicle object that interacts with the obstacle.
        '''
        if self.detect_collision(vehicle):
            self.apply_effect(vehicle)