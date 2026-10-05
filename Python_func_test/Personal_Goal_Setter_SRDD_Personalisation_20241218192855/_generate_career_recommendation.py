def _generate_career_recommendation(self, goal):
        '''
        Generates a career-related recommendation for a given goal.
        '''
        template = random.choice(self.career_templates)
        return template.format(name=goal[f'name'])