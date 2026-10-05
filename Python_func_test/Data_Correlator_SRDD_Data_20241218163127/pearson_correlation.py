def pearson_correlation(self, x, y):
        '''
        Computes the Pearson correlation coefficient between two variables.
        Args:
            x (array-like): First variable.
            y (array-like): Second variable.
        Returns:
            float: Pearson correlation coefficient.
        '''
        return np.corrcoef(x, y)[0, 1]