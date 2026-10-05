def _crossover(self, parent1, parent2):
        '''
        Combine traits from two parents to produce a child.
        '''
        crossover_point = random.randint(1, 3)
        child = parent1[:crossover_point] + parent2[crossover_point:]
        return child