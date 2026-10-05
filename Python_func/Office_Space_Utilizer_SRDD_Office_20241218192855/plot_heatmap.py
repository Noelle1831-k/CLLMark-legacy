def plot_heatmap(self, data):
        '''
        Plot a heatmap to visualize occupancy patterns over time.
        '''
        data['hour'] = data['timestamp'].dt.hour
        data['day'] = data['timestamp'].dt.day_name()
        pivot_table = data.pivot_table(values='occupancy', index='day', columns='hour', aggfunc='mean')
        plt.figure(figsize=(12, 6))
        sns.heatmap(pivot_table, cmap='coolwarm', annot=True, fmt=".1f")
        plt.title('Average Occupancy Heatmap')
        plt.xlabel('Hour of Day')
        plt.ylabel('Day of Week')
        plt.show()