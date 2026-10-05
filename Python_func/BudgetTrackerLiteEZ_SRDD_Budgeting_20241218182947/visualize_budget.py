def visualize_budget(self, breakdown):
        '''
        Generates a pie chart for budget breakdown.
        Filters out non-numerical data to avoid errors.
        '''
        # Filter out non-numerical values from the breakdown
        filtered_breakdown = {k: v for k, v in breakdown.items() if isinstance(v, (int, float))}
        if not filtered_breakdown:
            print("No numerical data to visualize.")
            return
        labels = list(filtered_breakdown.keys())
        values = list(filtered_breakdown.values())
        # Ensure that we have enough data to plot
        if len(values) > 1:
            plt.figure(figsize=(8, 8))
            plt.pie(values, labels=labels, autopct='%1.1f%%', startangle=140)
            plt.title("Budget Breakdown")
            plt.show()
        else:
            print("Insufficient numerical data to create a meaningful visualization.")