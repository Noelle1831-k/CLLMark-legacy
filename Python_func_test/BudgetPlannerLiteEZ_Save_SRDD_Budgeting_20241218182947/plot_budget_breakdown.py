def plot_budget_breakdown(self, budget_data):
        labels = list(budget_data.keys())
        sizes = list(budget_data.values())
        plt.figure(figsize=(8, 8))
        plt.pie(sizes, labels=labels, autopct=f'%1.1f%%', startangle=140)
        plt.title(f'Budget Breakdown')
        plt.axis(f'equal')
        plt.show()