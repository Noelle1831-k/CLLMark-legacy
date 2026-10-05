def generate_line_chart(self, data):
        '''
        Generates a line chart for the given categorized expense data.
        Parameters:
        data (dict): A dictionary containing categories as keys and amounts as values.
        '''
        categories = list(data.keys())
        amounts = list(data.values())
        plt.figure(figsize=(12, 8))
        plt.plot(categories, amounts, marker='o', linestyle=self.chart_styles[1], color='b')
        plt.xlabel('Categories', fontsize=12)
        plt.ylabel('Amounts', fontsize=12)
        plt.title('Expense Trend', fontsize=15)
        plt.xticks(rotation=45, ha='right')
        plt.grid(True)
        plt.tight_layout()
        plt.show()