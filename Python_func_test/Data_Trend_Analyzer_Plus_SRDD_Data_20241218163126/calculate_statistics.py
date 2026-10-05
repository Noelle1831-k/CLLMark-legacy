def calculate_statistics(self, data):
        '''
        Calculate statistical metrics.
        '''
        mean = np.mean(data)
        median = np.median(data)
        std_dev = np.std(data)
        return {'mean': mean, 'median': median, 'std_dev': std_dev}