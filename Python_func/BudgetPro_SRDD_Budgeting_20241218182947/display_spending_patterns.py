def display_spending_patterns(self, summary):
        '''
        Display a bar chart of spending patterns.
        '''
        categories = ['Total Expenses', 'Remaining Budget']
        values = [summary['Total Expenses'], summary['Remaining Budget']]
        plt.bar(categories, values, color=['lightcoral', 'lightskyblue'])
        plt.xlabel('Categories')
        plt.ylabel('Amount')
        plt.title('Spending Patterns')
        plt.show()