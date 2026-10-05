def move(self):
        if self.type == "moving":
            self.position += random.randint(-5, 5)
            self.position = max(0, min(100, self.position))  # Ensure position stays within bounds
            print(f"Target moved to {self.position}")