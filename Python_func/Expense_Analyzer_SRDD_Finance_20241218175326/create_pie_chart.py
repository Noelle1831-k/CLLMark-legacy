def create_pie_chart(self):
        '''
        Create a pie chart to visualize the distribution of expenses by category.
        '''
        category_totals = {}
        for expense in self.expenses:
            category = expense.get_category()
            amount = expense.get_amount()
            if category in category_totals:
                category_totals[category] += amount
            else:
                category_totals[category] = amount
        labels = category_totals.keys()
        sizes = category_totals.values()
        plt.pie(sizes, labels=labels, autopct='%1.1f%%')
        plt.axis('equal')
        plt.title('Expense Distribution by Category')
        plt.show()