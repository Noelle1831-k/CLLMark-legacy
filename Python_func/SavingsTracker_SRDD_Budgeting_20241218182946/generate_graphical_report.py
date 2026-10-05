def generate_graphical_report(self):
        labels = ['Income', 'Expenses']
        sizes = [sum([t.amount for t in self.user.income]), sum([t.amount for t in self.user.expenses])]
        colors = ['#ff9999','#66b3ff']
        explode = (0.1, 0)  # explode 1st slice
        plt.pie(sizes, explode=explode, labels=labels, colors=colors,
                autopct='%1.1f%%', shadow=True, startangle=140)
        plt.axis('equal')  # Equal aspect ratio ensures that pie is drawn as a circle.
        plt.title(f"Savings Overview for {self.user.name}")
        plt.show()