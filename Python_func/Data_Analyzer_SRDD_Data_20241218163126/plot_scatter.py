def plot_scatter(self, data, column1, column2):
        # Plot scatter plot
        plt.scatter(data[column1], data[column2])
        plt.title(f'Scatter Plot of {column1} vs {column2}')
        plt.xlabel(column1)
        plt.ylabel(column2)
        plt.show()