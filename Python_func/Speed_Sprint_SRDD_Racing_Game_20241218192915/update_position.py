def update_position(self, speed):
        self.position += speed
        if self.position > self.length:
            self.position = self.length
        print(f"Current position: {self.position}")