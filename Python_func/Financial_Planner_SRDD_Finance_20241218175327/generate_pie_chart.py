def generate_pie_chart(self, data):
        labels = data.keys()
        sizes = data.values()
        plt.pie(sizes, labels=labels, autopct='%1.1f%%')
        plt.axis('equal')
        plt.title('Expense Distribution')
        plt.show()