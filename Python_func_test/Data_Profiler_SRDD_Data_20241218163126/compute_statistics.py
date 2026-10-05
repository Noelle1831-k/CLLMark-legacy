def compute_statistics(self, data):
        for column in data.select_dtypes(include=['float64', 'int64']).columns:
            mean = data[column].mean()
            median = data[column].median()
            std_dev = data[column].std()
            print(f"Statistics for column {column}:")
            print(f"Mean: {mean}, Median: {median}, Standard Deviation: {std_dev}")