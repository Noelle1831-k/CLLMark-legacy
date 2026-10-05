def _calculate_average_occupancy(self, data):
        '''
        Calculate the average occupancy.
        '''
        return data['occupancy'].mean()