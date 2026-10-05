def assess_risk_factors(self, challenge):
        '''
        Assesses risk factors based on challenge difficulty and random events.
        '''
        risk_factors = {'high': False, 'medium': False, 'low': False}
        difficulty = challenge.difficulty
        random_factor = random.random()
        print(f"Random factor for risk assessment: {random_factor}")
        if difficulty > 7 or random_factor > 0.8:
            risk_factors['high'] = True
        elif 4 < difficulty <= 7 or 0.5 < random_factor <= 0.8:
            risk_factors['medium'] = True
        else:
            risk_factors['low'] = True
        return risk_factors