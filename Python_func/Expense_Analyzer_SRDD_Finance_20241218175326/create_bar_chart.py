def create_bar_chart(self):
        '''
        Create a bar chart to visualize the total expenses by category.
        '''
        category_totals = {}
        for expense in self.expenses:
            category = expense.get_category()
            amount = expense.get_amount()
            if category in category_totals:
                category_totals[category] += amount
            else:
                category_totals[category] = amount
        categories = list(category_totals.keys())
        totals = list(category_totals.values())
        plt.bar(categories, totals)
        plt.xlabel('Category')
        plt.ylabel('Total Amount')
        plt.title('Expenses by Category')
        plt.show()