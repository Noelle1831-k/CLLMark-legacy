def plot_pie_chart(self, progress_data, category):
        '''
        Plots the progress data using a pie chart to show distribution.
        Parameters:
        - progress_data: List of progress values over time.
        - category: The category of the habit being tracked.
        '''
        labels = [f'Day {i+1}' for i in range(len(progress_data))]
        plt.figure(figsize=(8, 8))
        plt.pie(progress_data, labels=labels, autopct='%1.1f%%', startangle=140)
        plt.title(f'{category.capitalize()} Progress Distribution')
        plt.axis('equal')  # Equal aspect ratio ensures that pie is drawn as a circle.
        plt.show()