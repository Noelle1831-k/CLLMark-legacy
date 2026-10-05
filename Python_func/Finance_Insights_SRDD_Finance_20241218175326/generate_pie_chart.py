def generate_pie_chart(self, data):
        '''
        Generate a pie chart for expenses.
        '''
        labels = [item['category'] for item in data]
        sizes = [item['amount'] for item in data]
        explode = [0.1 if max(sizes) == size else 0 for size in sizes]
        plt.figure(figsize=(10, 7))
        plt.pie(sizes, labels=labels, autopct='%1.1f%%', startangle=140, explode=explode, colors=self.colors[:len(labels)])
        plt.axis('equal')
        plt.title('Expense Distribution')
        plt.show()