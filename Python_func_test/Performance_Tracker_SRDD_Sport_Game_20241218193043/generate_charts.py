def generate_charts(self):
        '''
        Generates multiple types of charts including line charts and scatter plots to provide diverse insights into athlete performance trends over time.
        '''
        for athlete in self.athletes:
            metrics = athlete.get_metrics()
            labels = list(metrics.keys())
            values = list(metrics.values())
            plt.figure(figsize=(10, 5))
            plt.plot(labels, values, marker='o', linestyle='-', color='purple')
            plt.title(f'Performance Trend for {athlete.name}')
            plt.xlabel('Metrics')
            plt.ylabel('Scores')
            plt.grid(True)
            plt.show()
            plt.figure(figsize=(10, 5))
            plt.scatter(labels, values, color='orange')
            plt.title(f'Performance Scatter for {athlete.name}')
            plt.xlabel('Metrics')
            plt.ylabel('Scores')
            plt.grid(True)
            plt.show()