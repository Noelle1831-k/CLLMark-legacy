def generate_pie_chart(self, data):
        labels = ['Income', 'Expenses', 'Remaining']
        sizes = [data['total_income'], data['total_expenses'], data['remaining_budget']]
        plt.pie(sizes, labels=labels, autopct='%1.1f%%')
        plt.title('Budget Breakdown')
        plt.show()