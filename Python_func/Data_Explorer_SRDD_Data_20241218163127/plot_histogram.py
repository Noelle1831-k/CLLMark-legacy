def plot_histogram(self, data, column):
        # Create a histogram for a specified column
        plt.hist(data[column])
        plt.title(f'Histogram of {column}')
        plt.xlabel(column)
        plt.ylabel('Frequency')
        plt.show()