def plot_bar_chart(self, progress_data, category):
        '''
        Plots the progress data using a bar chart.
        Parameters:
        - progress_data: List of progress values over time.
        - category: The category of the habit being tracked.
        '''
        days = list(range(1, len(progress_data) + 1))
        plt.figure(figsize=(10, 5))
        plt.bar(days, progress_data, color='g', alpha=0.7)
        plt.ylabel('Progress')
        plt.xlabel('Days')
        plt.title(f'{category.capitalize()} Progress Bar Chart')
        plt.xticks(days)
        plt.grid(axis='y')
        plt.show()