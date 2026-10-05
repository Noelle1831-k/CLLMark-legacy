def analyze_data(self, data):
        """
        Analyze the data by performing basic statistical analysis and data cleaning.
        Parameters:
        data (DataFrame): The data to be analyzed.
        Returns:
        DataFrame: The analyzed data with additional statistical metrics.
        """
        try:
            # Data Cleaning: Remove missing values
            data_cleaned = data.dropna()
            print("Data cleaning completed. Missing values removed.")
            # Basic Statistical Analysis
            stats = data_cleaned.describe()
            print("Basic statistics calculated.")
            # Additional Analysis: Correlation matrix
            correlation_matrix = data_cleaned.corr()
            print("Correlation matrix calculated.")
            # Return the cleaned data and statistics
            return data_cleaned, stats, correlation_matrix
        except Exception as e:
            print(f"Error analyzing data: {e}")