def decelerate(self):
        if self.current_gear > 1:
            self.current_gear -= 1
            self.current_speed = max(0, self.current_speed - 10 * self.current_gear)