def show_pie_chart(self, expenses):
        labels = [f'Expense {i+1}' for i in range(len(expenses))]
        plt.pie(expenses, labels=labels, autopct='%1.1f%%')
        plt.title('Expense Distribution')
        plt.show()