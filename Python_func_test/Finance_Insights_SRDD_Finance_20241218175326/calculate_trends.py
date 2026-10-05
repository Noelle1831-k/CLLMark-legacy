def calculate_trends(self, user_data):
        '''
        Calculate financial trends.
        '''
        trends = {'income': [], 'expenses': []}
        for income in user_data['income']:
            trends['income'].append(income['amount'])
        for expense in user_data['expenses']:
            trends['expenses'].append(expense['amount'])
        return trends