def _initialize_population(self, characters, population_size):
        '''
        Generate the initial population of combinations.
        '''
        population = []
        for _ in range(population_size):
            individual = random.sample(characters, 4)
            population.append(individual)
        return population