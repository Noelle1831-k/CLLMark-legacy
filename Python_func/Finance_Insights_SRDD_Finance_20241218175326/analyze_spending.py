def analyze_spending(self, data):
        '''
        Analyze spending habits.
        '''
        categories = {}
        for expense in data['expenses']:
            category = expense['category']
            amount = expense['amount']
            if category in categories:
                categories[category] += amount
            else:
                categories[category] = amount
        return categories