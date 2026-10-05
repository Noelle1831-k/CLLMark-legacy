def plot_savings_progress(self, budget_data):
        savings = budget_data["Savings"]
        goal = budget_data["Savings Goal"]
        plt.figure(figsize=(6, 4))
        plt.bar(['Savings', 'Goal'], [savings, goal], color=['blue', 'green'])
        plt.title('Savings Progress')
        plt.ylabel('Amount ($)')
        plt.show()