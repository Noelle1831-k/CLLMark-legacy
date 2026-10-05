def plot_distribution(self, data):
        '''
        Plot the distribution of occupancy to understand variability.
        '''
        plt.figure(figsize=(10, 5))
        sns.histplot(data['occupancy'], bins=20, kde=True, color='green')
        plt.title('Occupancy Distribution')
        plt.xlabel('Occupancy')
        plt.ylabel('Frequency')
        plt.grid(True)
        plt.tight_layout()
        plt.show()