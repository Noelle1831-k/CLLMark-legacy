def evaluate_risks(self, challenge):
        '''
        Evaluates risks of different options and selects the best course of action.
        '''
        risk_factors = self.assess_risk_factors(challenge)
        print(f"Risk factors assessed: {risk_factors}")
        if risk_factors['high']:
            return "mitigate"
        elif risk_factors['medium']:
            return "balance"
        else:
            return "exploit"