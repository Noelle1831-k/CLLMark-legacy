def move(self, direction):
        x, y = self.position
        if direction == "up":
            self.position = [x, y + 1 * self.speed_multiplier]
        elif direction == "down":
            self.position = [x, y - 1 * self.speed_multiplier]
        elif direction == "left":
            self.position = [x - 1 * self.speed_multiplier, y]
        elif direction == "right":
            self.position = [x + 1 * self.speed_multiplier, y]
        print(f"{self.name} moved {direction} to position {self.position}")