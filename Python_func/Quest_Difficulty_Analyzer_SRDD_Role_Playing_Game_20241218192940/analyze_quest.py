def analyze_quest(self, quest_params):
        if self.validator.validate_parameters(quest_params):
            difficulty = self.calculator.calculate_difficulty(quest_params)
            return difficulty
        else:
            raise ValueError("Invalid quest parameters: Parameters must be within the range of 0 to 100.")