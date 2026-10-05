def generate_pie_chart(self, user):
        '''
        Generates a pie chart showing the distribution of income and expenses.
        '''
        labels = ['Income', 'Expenses']
        sizes = [sum(t.amount for t in user.income), sum(t.amount for t in user.expenses)]
        colors = ['gold', 'lightcoral']
        explode = (0.1, 0)  # explode 1st slice
        plt.figure(figsize=(8, 8))
        plt.pie(sizes, explode=explode, labels=labels, colors=colors,
                autopct='%1.1f%%', shadow=True, startangle=140)
        plt.axis('equal')
        plt.title('Income vs Expenses Distribution')
        plt.show()