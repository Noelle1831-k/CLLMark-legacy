def accelerate(self):
        if self.gears > self.current_gear:
            self.current_gear += 1
            self.current_speed = min(self.max_speed, self.current_speed + 10 * self.current_gear)