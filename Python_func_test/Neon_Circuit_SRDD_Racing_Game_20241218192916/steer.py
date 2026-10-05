def steer(self, direction):
        self.direction += direction
        self.update_position()