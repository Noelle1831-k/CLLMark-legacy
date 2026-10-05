def generate_bar_chart(self, user):
        '''
        Generates a bar chart comparing income and expenses.
        '''
        categories = ['Income', 'Expenses']
        values = [sum(t.amount for t in user.income), sum(t.amount for t in user.expenses)]
        plt.figure(figsize=(10, 6))
        plt.bar(categories, values, color=['blue', 'red'])
        plt.xlabel('Category')
        plt.ylabel('Amount')
        plt.title('Income vs Expenses')
        plt.grid(axis='y', linestyle='--', alpha=0.7)
        plt.show()