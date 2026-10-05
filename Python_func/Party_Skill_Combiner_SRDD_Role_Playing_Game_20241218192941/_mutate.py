def _mutate(self, individual):
        '''
        Introduce a mutation by replacing one character in the combination.
        '''
        index = random.randint(0, 3)
        new_character = random.choice(individual)
        individual[index] = new_character
        return individual