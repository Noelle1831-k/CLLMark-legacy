def plot_bar(self, data, column):
        # Create a bar chart for a specified column
        data[column].value_counts().plot(kind='bar')
        plt.title(f'Bar Chart of {column}')
        plt.xlabel(column)
        plt.ylabel('Count')
        plt.show()