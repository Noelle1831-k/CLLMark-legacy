def calculate(self, dataframe, columns):
        '''
        Calculates the correlation matrix for the selected columns.
        Args:
            dataframe (pd.DataFrame): The dataset.
            columns (list): The selected columns for correlation analysis.
        Returns:
            np.ndarray: The correlation matrix.
        '''
        correlation_matrix = np.zeros((len(columns), len(columns)))
        for i, col_i in enumerate(columns):
            for j, col_j in enumerate(columns):
                x = dataframe[col_i]
                y = dataframe[col_j]
                if i == j:
                    correlation_matrix[i, j] = 1.0
                else:
                    correlation_matrix[i, j] = self.pearson_correlation(x, y)
        return correlation_matrix