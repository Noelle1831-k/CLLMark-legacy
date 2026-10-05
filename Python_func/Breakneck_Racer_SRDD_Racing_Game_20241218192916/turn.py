def turn(self, direction):
        if direction == "left":
            self.position[0] -= self.handling
        elif direction == "right":
            self.position[0] += self.handling