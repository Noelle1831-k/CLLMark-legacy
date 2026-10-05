def move(self, direction):
        if direction == "forward":
            self.position = (self.position[0] + 1, self.position[1])
        elif direction == "backward":
            self.position = (self.position[0] - 1, self.position[1])
        elif direction == "up":
            self.position = (self.position[0], self.position[1] - 1)
        elif direction == "down":
            self.position = (self.position[0], self.position[1] + 1)