def genetic_algorithm_optimization(self, characters, population_size=10, generations=50, mutation_rate=0.1):
        '''
        Optimize the party using a genetic algorithm.
        '''
        population = self._initialize_population(characters, population_size)
        for _ in range(generations):
            population = self._evolve_population(population, mutation_rate)
        return max(population, key=self._calculate_combination_effectiveness)