def analyze_income(self, data):
        '''
        Analyze income sources.
        '''
        sources = {}
        for income in data['income']:
            source = income['category']
            amount = income['amount']
            if source in sources:
                sources[source] += amount
            else:
                sources[source] = amount
        return sources