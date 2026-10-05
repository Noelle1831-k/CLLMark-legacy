def generate_chart(self, data):
        '''
        Generates a bar chart for the given categorized expense data.
        Parameters:
        data (dict): A dictionary containing categories as keys and amounts as values.
        '''
        categories = list(data.keys())
        amounts = list(data.values())
        plt.figure(figsize=(12, 8))
        plt.bar(categories, amounts, color=self.chart_colors[:len(categories)])
        plt.xlabel('Categories', fontsize=12)
        plt.ylabel('Amounts', fontsize=12)
        plt.title('Expense Chart', fontsize=15)
        plt.xticks(rotation=45, ha='right')
        plt.grid(axis='y', linestyle=self.chart_styles[0])
        plt.tight_layout()
        plt.show()