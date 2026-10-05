def show_bar_chart(self, income, expenses):
        categories = ['Income', 'Expenses']
        values = [sum(income), sum(expenses)]
        plt.bar(categories, values)
        plt.title('Income vs Expenses')
        plt.show()