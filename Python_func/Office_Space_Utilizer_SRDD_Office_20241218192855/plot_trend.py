def plot_trend(self, data):
        '''
        Plot a trend line to show occupancy changes over time.
        '''
        plt.figure(figsize=(14, 7))
        sns.lineplot(x='timestamp', y='occupancy', data=data, marker='o', color='purple')
        plt.title('Occupancy Trend Over Time')
        plt.xlabel('Time')
        plt.ylabel('Occupancy')
        plt.xticks(rotation=45)
        plt.grid(True)
        plt.tight_layout()
        plt.show()