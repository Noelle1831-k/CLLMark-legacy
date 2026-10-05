def _identify_occupancy_trends(self, data):
        '''
        Identify trends in occupancy over time.
        '''
        data['hour'] = data['timestamp'].dt.hour
        hourly_trends = data.groupby('hour')['occupancy'].mean()
        return hourly_trends