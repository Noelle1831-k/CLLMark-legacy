def move(self, direction):
        x, y = self.position
        if direction == 'up':
            y += 1
        elif direction == 'down':
            y -= 1
        elif direction == 'left':
            x -= 1
        elif direction == 'right':
            x += 1
        self.position = (x, y)
        print(f"Player moved {direction} to position {self.position}")