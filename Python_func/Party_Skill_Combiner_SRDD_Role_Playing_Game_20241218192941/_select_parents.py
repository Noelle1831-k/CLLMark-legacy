def _select_parents(self, population):
        '''
        Select two distinct parents for crossover.
        '''
        parent1 = random.choice(population)
        parent2 = random.choice([ind for ind in population if ind != parent1])
        return parent1, parent2