def perform(self):
        # Simulate exercise performance with a random result
        result = random.randint(1, 100)
        print(f"Performing {self.name} exercise... Result: {result}")
        return result