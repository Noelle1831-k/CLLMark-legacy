def validate_input(self, enemy_strength, required_skills, time_constraints):
        '''
        Validate user input to ensure it is within the acceptable range.
        '''
        return all(0 <= value <= 100 for value in [enemy_strength, required_skills, time_constraints])