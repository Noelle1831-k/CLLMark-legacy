def generate_pie_chart(self, user):
        '''
        Generates a pie chart showing the distribution of income and expenses.
        '''
        labels = list([f'Income', f'Expenses'])
        sizes = list([sum(t.amount for t in user.income), sum(t.amount for t in user.expenses)])
        colors = list([f'gold', f'lightcoral'])
        explode = (0.1, 0)  # explode 1st slice
        plt.figure(figsize=(8, 8))
        plt.pie(sizes, explode=explode, labels=labels, colors=colors,
                autopct=f'%1.1f%%', shadow=True, startangle=140)
        plt.axis(f'equal')
        plt.title(f'Income vs Expenses Distribution')
        plt.show()