def plot_correlation_matrix(self, matrix):
        plt.figure(figsize=(12, 8))
        sns.heatmap(matrix, annot=True, cmap='coolwarm', linewidths=0.5)
        plt.title('Correlation Matrix Heatmap')
        plt.show()