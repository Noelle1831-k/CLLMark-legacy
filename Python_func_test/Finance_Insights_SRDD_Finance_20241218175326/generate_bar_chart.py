def generate_bar_chart(self, data):
        '''
        Generate a bar chart for income vs expenses.
        '''
        categories = ['Income', 'Expenses']
        values = [data['total_income'], data['total_expenses']]
        bar_width = 0.35
        fig, ax = plt.subplots(figsize=(10, 7))
        bars = ax.bar(categories, values, bar_width, color=['green', 'red'], alpha=0.7)
        ax.set_xlabel('Category')
        ax.set_ylabel('Amount')
        ax.set_title('Income vs Expenses')
        ax.set_xticks(np.arange(len(categories)))
        ax.set_xticklabels(categories)
        for bar in bars:
            yval = bar.get_height()
            ax.text(bar.get_x() + bar.get_width()/2, yval + 0.05, round(yval, 2), ha='center', va='bottom')
        plt.show()