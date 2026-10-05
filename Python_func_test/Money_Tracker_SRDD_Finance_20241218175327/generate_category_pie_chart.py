def generate_category_pie_chart(self, user):
        '''
        Generates a pie chart showing the distribution of expenses across different categories.
        '''
        labels = user.categories.keys()
        sizes = [sum(t.amount for t in category.transactions) for category in user.categories.values()]
        colors = plt.cm.Paired(np.arange(len(labels)))
        plt.figure(figsize=(8, 8))
        plt.pie(sizes, labels=labels, colors=colors, autopct="%1.1f%%", shadow=True, startangle=140)
        plt.axis("equal")
        plt.title("Expenses by Category")
        plt.show()