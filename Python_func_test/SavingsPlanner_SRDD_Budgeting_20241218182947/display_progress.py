def display_progress(self, progress):
        """
        Displays a pie chart of the savings progress.
        """
        try:
            plt.figure(figsize=(6, 6))
            labels = 'Achieved', 'Remaining'
            sizes = [progress, 100 - progress]
            colors = ['green', 'red']
            plt.pie(sizes, labels=labels, colors=colors, autopct='%1.1f%%', startangle=140)
            plt.title("Savings Progress")
            plt.show()
        except Exception as e:
            print(f"An error occurred while displaying the chart: {e}")