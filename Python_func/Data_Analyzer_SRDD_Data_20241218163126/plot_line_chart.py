def plot_line_chart(self, data, column):
        # Plot line chart
        plt.plot(data[column])
        plt.title(f'Line Chart of {column}')
        plt.xlabel('Index')
        plt.ylabel(column)
        plt.show()