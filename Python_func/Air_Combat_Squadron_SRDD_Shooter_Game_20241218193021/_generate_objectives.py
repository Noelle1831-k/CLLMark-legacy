def _generate_objectives(self):
        '''
        Generate a list of objectives based on the mission difficulty level.
        '''
        possible_objectives = [
            "Destroy enemy base",
            "Escort ally aircraft",
            "Eliminate enemy squadron",
            "Collect intelligence from enemy territory",
            "Defend allied base",
        ]
        num_objectives = min(3, self.difficulty_level + 1)  # More objectives for higher difficulty
        return random.sample(possible_objectives, num_objectives)