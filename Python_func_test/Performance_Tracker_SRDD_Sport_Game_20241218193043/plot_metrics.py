def plot_metrics(self):
        '''
        Plots bar charts for each athlete's performance metrics, providing a visual comparison of speed, agility, and accuracy.
        '''
        for athlete in self.athletes:
            metrics = athlete.get_metrics()
            labels = list(metrics.keys())
            values = list(metrics.values())
            fig, ax = plt.subplots()
            ax.bar(labels, values, color=['blue', 'green', 'red'])
            ax.set_ylabel('Scores')
            ax.set_title(f'Performance Metrics for {athlete.name}')
            ax.set_ylim(0, 100)
            plt.xticks(rotation=45)
            plt.tight_layout()
            plt.show()