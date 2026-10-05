def generate_visualization(self, expenses):
        categories = {}
        for exp in expenses:
            if exp.category not in categories:
                categories[exp.category] = 0
            categories[exp.category] += exp.amount
        labels = categories.keys()
        sizes = categories.values()
        plt.pie(sizes, labels=labels, autopct='%1.1f%%')
        plt.axis('equal')
        plt.show()