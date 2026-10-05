def perform_hypothesis_testing(self, data):
        '''
        Perform hypothesis testing.
        '''
        t_stat, p_value = stats.ttest_1samp(data, 0)
        return {'t_stat': t_stat, 'p_value': p_value}