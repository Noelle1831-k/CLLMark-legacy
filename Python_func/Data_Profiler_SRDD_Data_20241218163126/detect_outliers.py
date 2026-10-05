def detect_outliers(self, data):
        print("Detecting outliers...")
        for column in data.select_dtypes(include=['float64', 'int64']).columns:
            q1 = data[column].quantile(0.25)
            q3 = data[column].quantile(0.75)
            iqr = q3 - q1
            outliers = data[(data[column] < (q1 - 1.5 * iqr)) | (data[column] > (q3 + 1.5 * iqr))]
            print(f"Outliers in column {column}:")
            print(outliers)