def plot_progress(self, progress_data, category):
        '''
        Plots the progress data over time using a line chart.
        Parameters:
        - progress_data: List of progress values over time.
        - category: The category of the habit being tracked.
        '''
        days = list(range(1, len(progress_data) + 1))
        plt.figure(figsize=(10, 5))
        plt.plot(days, progress_data, marker='o', linestyle='-', color='b', label=category)
        plt.ylabel('Progress')
        plt.xlabel('Days')
        plt.title(f'{category.capitalize()} Progress Over Time')
        plt.legend()
        plt.grid(True)
        plt.show()