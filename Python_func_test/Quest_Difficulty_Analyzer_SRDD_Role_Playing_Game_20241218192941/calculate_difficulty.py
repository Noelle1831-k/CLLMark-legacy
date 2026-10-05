def calculate_difficulty(self):
        '''
        Calculate the difficulty rating of the quest.
        '''
        enemy_factor = self.calculator.calculate_enemy_factor(self.parameters.enemy_strength)
        skill_factor = self.calculator.calculate_skill_factor(self.parameters.required_skills)
        time_factor = self.calculator.calculate_time_factor(self.parameters.time_constraints)
        difficulty = (enemy_factor + skill_factor + time_factor) / 3
        return difficulty