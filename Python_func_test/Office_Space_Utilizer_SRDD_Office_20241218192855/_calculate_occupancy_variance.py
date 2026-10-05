def _calculate_occupancy_variance(self, data):
        '''
        Calculate the variance in occupancy.
        '''
        return data['occupancy'].var()