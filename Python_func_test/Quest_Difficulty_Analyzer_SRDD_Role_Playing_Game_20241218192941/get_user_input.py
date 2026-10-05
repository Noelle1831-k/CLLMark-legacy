def get_user_input(self):
        '''
        Collect quest parameters from the user.
        '''
        while True:
            try:
                enemy_strength = float(input('Enter enemy strength (0-100): '))
                required_skills = float(input('Enter required skills (0-100): '))
                time_constraints = float(input('Enter time constraints (0-100): '))
                if self.validate_input(enemy_strength, required_skills, time_constraints):
                    return enemy_strength, required_skills, time_constraints
                else:
                    print('Input values must be between 0 and 100.', end='\n')
            except ValueError:
                print('Invalid input. Please enter numeric values.', end='\n')