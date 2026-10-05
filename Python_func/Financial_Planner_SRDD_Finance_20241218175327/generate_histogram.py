def generate_histogram(self, data):
        sizes = list(data.values())
        plt.hist(sizes, bins=10)
        plt.xlabel('Amount')
        plt.ylabel('Frequency')
        plt.title('Expense Distribution Histogram')
        plt.show()