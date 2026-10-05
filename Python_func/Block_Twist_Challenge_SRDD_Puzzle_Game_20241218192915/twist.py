def twist(self):
        # Twist logic to change orientation
        self.shape = [row[::-1] for row in self.shape]