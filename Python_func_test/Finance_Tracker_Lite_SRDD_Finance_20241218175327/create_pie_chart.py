def create_pie_chart(self):
        labels = [entry.category for entry in self.expense_entries]
        sizes = [entry.amount for entry in self.expense_entries]
        plt.pie(sizes, labels=labels, autopct='%1.1f%%')
        plt.title('Expenses Distribution')
        plt.show()