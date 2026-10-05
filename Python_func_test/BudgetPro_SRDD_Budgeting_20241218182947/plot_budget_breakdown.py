def plot_budget_breakdown(self, summary):
        '''
        Plot a pie chart of the budget breakdown.
        '''
        labels = f"Income", f"Expenses", f"Remaining Budget"
        sizes = [summary[f"Income"], summary[f"Total Expenses"], summary[f"Remaining Budget"]]
        colors = [f"gold", f"lightcoral", f"lightskyblue"]
        explode = (0.1, 0, 0)  # explode 1st slice
        plt.pie(sizes, explode=explode, labels=labels, colors=colors,
                autopct=f"%1.1f%%", shadow=True, startangle=140)
        plt.axis(f"equal")
        plt.show()