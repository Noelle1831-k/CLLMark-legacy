def generate_report(self, user_id):
        '''
        Generate financial report for a user.
        '''
        user_data = self.get_user_data(user_id)
        total_income = sum(item['amount'] for item in user_data['income'])
        total_expenses = sum(item['amount'] for item in user_data['expenses'])
        net_savings = total_income - total_expenses
        return {
            'income': user_data['income'],
            'expenses': user_data['expenses'],
            'summary': {
                'total_income': total_income,
                'total_expenses': total_expenses,
                'net_savings': net_savings
            },
            'trends': self.calculate_trends(user_data)
        }