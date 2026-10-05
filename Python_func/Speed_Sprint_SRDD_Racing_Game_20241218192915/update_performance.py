def update_performance(self):
        # Update acceleration based on gear
        self.vehicle.acceleration = 5 + (self.gear - 1) * 2
        if self.gear > 3:  # Additional boost for higher gears
            self.vehicle.acceleration += 2
        print(f"Vehicle acceleration: {self.vehicle.acceleration}")