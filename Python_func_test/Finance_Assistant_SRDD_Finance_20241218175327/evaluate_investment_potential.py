def evaluate_investment_potential(self):
        '''
        Evaluates if the user has the potential for investing based on income, expenses, and savings.
        Returns:
        bool: True if the user has the financial capacity to invest; False otherwise.
        '''
        if self.user_profile.income > 3000 and self.analysis_report['budget'] > 500 and self.analysis_report['savings_rate'] > 20:
            return True
        return False