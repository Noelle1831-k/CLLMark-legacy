def plot_scatter(self, data, x_column, y_column):
        # Create a scatter plot for specified x and y columns
        plt.scatter(data[x_column], data[y_column])
        plt.title(f'Scatter Plot of {x_column} vs {y_column}')
        plt.xlabel(x_column)
        plt.ylabel(y_column)
        plt.show()