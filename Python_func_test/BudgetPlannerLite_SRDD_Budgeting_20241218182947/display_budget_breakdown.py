def display_budget_breakdown(self):
        '''
        Display a pie chart of the budget breakdown.
        '''
        labels = ['Income', 'Expenses']
        sizes = [self.planner.get_total_income(), self.planner.get_total_expenses()]
        colors = ['green', 'red']
        explode = (0.1, 0)
        plt.pie(sizes, explode=explode, labels=labels, colors=colors, autopct='%1.1f%%', shadow=True, startangle=140)
        plt.axis('equal')
        plt.title('Budget Breakdown')
        plt.show()