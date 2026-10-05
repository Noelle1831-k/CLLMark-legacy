def mutate(self):
        mutation_factor = random.uniform(0.85, 1.15)
        self.health = self.health * mutation_factor
        self.speed = self.speed * mutation_factor
        self.reproduction_rate = self.reproduction_rate * mutation_factor
        self.camouflage = self.camouflage * mutation_factor
        self.vision = self.vision * mutation_factor