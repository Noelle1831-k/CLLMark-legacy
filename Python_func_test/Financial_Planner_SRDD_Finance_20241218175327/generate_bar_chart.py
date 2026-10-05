def generate_bar_chart(self, data):
        labels = data.keys()
        sizes = data.values()
        plt.bar(labels, sizes)
        plt.xlabel('Categories')
        plt.ylabel('Amount')
        plt.title('Expenses by Category')
        plt.show()