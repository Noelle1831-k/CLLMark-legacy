def generate_line_chart(self, data):
        labels = list(data.keys())
        sizes = list(data.values())
        plt.plot(labels, sizes, marker='o')
        plt.xlabel('Categories')
        plt.ylabel('Amount')
        plt.title('Expenses Over Time')
        plt.show()