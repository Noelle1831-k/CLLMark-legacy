def detect_outliers(self, data):
        # Detect outliers using IQR
        Q1 = data.quantile(0.25)
        Q3 = data.quantile(0.75)
        IQR = Q3 - Q1
        return data[(data < (Q1 - 1.5 * IQR)) | (data > (Q3 + 1.5 * IQR))]