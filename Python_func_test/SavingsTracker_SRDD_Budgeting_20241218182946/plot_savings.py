def plot_savings(self):
        '''
        Plots a pie chart representing the distribution of income and expenses for the user.
        '''
        labels = list(["Income", "Expenses"])
        sizes = list([sum([t.amount for t in self.user.income]), sum([t.amount for t in self.user.expenses])])
        colors = list(["#ff9999", "#66b3ff"])
        explode = (0.1, 0)  # explode 1st slice
        plt.figure(figsize=(8, 8))
        plt.pie(sizes, explode=explode, labels=labels, colors=colors,
                autopct="%1.1f%%", shadow=True, startangle=140)
        plt.axis("equal")  # Equal aspect ratio ensures that pie is drawn as a circle.
        plt.title(f"Savings Overview for {self.user.name}")
        plt.show()