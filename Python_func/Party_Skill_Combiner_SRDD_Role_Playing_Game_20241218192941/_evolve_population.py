def _evolve_population(self, population, mutation_rate):
        '''
        Perform evolution on the population using selection, crossover, and mutation.
        '''
        new_population = []
        for _ in range(len(population)):
            parent1, parent2 = self._select_parents(population)
            child = self._crossover(parent1, parent2)
            if random.random() < mutation_rate:
                child = self._mutate(child)
            new_population.append(child)
        return new_population