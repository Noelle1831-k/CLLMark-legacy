def generate_opponents(self, count):
        print("Generating Opponents...")
        return [Vehicle(f"Rival-{i}", random.randint(180, 220), 100) for i in range(count)]