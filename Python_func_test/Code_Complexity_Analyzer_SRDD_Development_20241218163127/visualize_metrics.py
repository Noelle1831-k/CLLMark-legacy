def visualize_metrics(self):
        labels = list(self.metrics.keys())
        values = list(self.metrics.values())
        plt.figure(figsize=(10, 5))
        plt.bar(labels, values, color=['blue', 'green', 'red'])
        plt.xlabel('Metrics')
        plt.ylabel('Values')
        plt.title('Code Complexity Metrics')
        plt.show()