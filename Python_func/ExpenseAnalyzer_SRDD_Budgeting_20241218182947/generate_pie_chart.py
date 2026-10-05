def generate_pie_chart(self, data):
        '''
        Generates a pie chart for the given categorized expense data.
        Parameters:
        data (dict): A dictionary containing categories as keys and amounts as values.
        '''
        categories = list(data.keys())
        amounts = list(data.values())
        plt.figure(figsize=(10, 7))
        plt.pie(amounts, labels=categories, autopct='%1.1f%%', startangle=140, colors=self.chart_colors[:len(categories)])
        plt.title('Expense Distribution', fontsize=15)
        plt.axis('equal')
        plt.show()