def create_visualizations(self, data):
        for column in data.select_dtypes(include=['float64', 'int64']).columns:
            plt.figure()
            data[column].hist()
            plt.title(f"Histogram of {column}")
            plt.xlabel(column)
            plt.ylabel('Frequency')
            plt.show()