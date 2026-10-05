def generate_pie_chart(self):
        labels = self.expenses.keys()
        sizes = self.expenses.values()
        plt.pie(sizes, labels=labels, autopct='%1.1f%%')
        plt.title('Expenses by Category')
        plt.show()