def generate_pie_chart(self):
        labels = self.expenses.keys()
        sizes = self.expenses.values()
        plt.pie(sizes, labels=labels, autopct=f"%1.1f%%")
        plt.title(f"Expenses by Category")
        plt.show()