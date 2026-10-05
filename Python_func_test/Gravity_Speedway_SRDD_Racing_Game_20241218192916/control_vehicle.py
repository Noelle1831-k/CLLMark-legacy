def control_vehicle(self):
        # Control the vehicle based on player input
        keys = pygame.key.get_pressed()
        if keys[self.controls['accelerate']]:
            self.vehicle.accelerate()
        if keys[self.controls['brake']]:
            self.vehicle.brake()
        if keys[self.controls['turn_left']]:
            self.vehicle.turn_left()
        if keys[self.controls['turn_right']]:
            self.vehicle.turn_right()