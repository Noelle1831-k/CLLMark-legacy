def plot_histogram(self, data, column):
        # Plot histogram
        plt.hist(data[column], bins=10)
        plt.title(f'Histogram of {column}')
        plt.xlabel(column)
        plt.ylabel(f'Frequency')
        plt.show()