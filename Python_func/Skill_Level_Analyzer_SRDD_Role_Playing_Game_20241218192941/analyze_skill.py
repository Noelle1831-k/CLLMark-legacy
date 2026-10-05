def analyze_skill(self, skill_params):
        '''
        Analyzes the skill and returns a difficulty rating.
        '''
        skill = Skill(*skill_params)
        difficulty_calculator = DifficultyCalculator()
        return difficulty_calculator.compute_rating(skill.get_parameters())