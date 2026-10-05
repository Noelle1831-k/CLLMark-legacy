def move(self, direction):
        if direction == "up":
            self.position = (self.position[0], self.position[1] + self.speed)
        elif direction == "down":
            self.position = (self.position[0], self.position[1] - self.speed)
        elif direction == "left":
            self.position = (self.position[0] - self.speed, self.position[1])
        elif direction == "right":
            self.position = (self.position[0] + self.speed, self.position[1])