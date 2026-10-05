def apply_effect(self, vehicle):
        '''
        Apply the obstacle's effect to the vehicle.
        :param vehicle: The vehicle object to apply the effect on.
        '''
        if self.effect == "slowdown":
            vehicle.speed = max(0, vehicle.speed - 2)  # Reduce speed as a slowdown effect
        elif self.effect == "damage":
            vehicle.acceleration = max(0, vehicle.acceleration - 1)  # Reduce acceleration as a damage effect
        # Additional effects can be added here