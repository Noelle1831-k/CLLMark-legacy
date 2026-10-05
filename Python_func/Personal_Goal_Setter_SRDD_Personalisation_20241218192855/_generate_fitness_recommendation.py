def _generate_fitness_recommendation(self, goal):
        '''
        Generates a fitness-related recommendation for a given goal.
        '''
        template = random.choice(self.fitness_templates)
        return template.format(name=goal['name'])