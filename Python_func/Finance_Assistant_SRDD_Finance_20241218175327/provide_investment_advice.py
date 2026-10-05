def provide_investment_advice(self):
        '''
        Provides basic investment advice based on the user's financial profile.
        Returns:
        str: A string containing investment advice.
        '''
        if self.analysis_report['investment_potential']:
            return "Consider starting with low-risk investment options like index funds or ETFs."
        else:
            return "You may want to focus on building an emergency fund before considering investments."