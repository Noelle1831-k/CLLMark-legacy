def mutate(self):
        mutation_factor = random.uniform(0.85, 1.15)
        self.health *= mutation_factor
        self.speed *= mutation_factor
        self.reproduction_rate *= mutation_factor
        self.camouflage *= mutation_factor
        self.vision *= mutation_factor