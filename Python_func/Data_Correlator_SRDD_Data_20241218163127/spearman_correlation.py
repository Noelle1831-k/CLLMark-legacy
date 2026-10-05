def spearman_correlation(self, x, y):
        '''
        Computes the Spearman correlation coefficient between two variables.
        Args:
            x (array-like): First variable.
            y (array-like): Second variable.
        Returns:
            float: Spearman correlation coefficient.
        '''
        return stats.spearmanr(x, y).correlation