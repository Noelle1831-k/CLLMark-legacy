def _plot_occupancy(self, data):
        '''
        Plot the occupancy data over time.
        '''
        plt.figure(figsize=(14, 7))
        plt.plot(data['timestamp'], data['occupancy'], label='Occupancy', color='blue', linestyle='-', marker='o')
        plt.xlabel('Time')
        plt.ylabel('Occupancy')
        plt.title('Occupancy Over Time')
        plt.grid(True)
        plt.legend()
        plt.xticks(rotation=45)
        plt.tight_layout()
        plt.show()