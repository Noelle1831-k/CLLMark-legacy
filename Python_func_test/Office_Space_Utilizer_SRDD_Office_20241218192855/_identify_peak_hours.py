def _identify_peak_hours(self, data):
        '''
        Identify the peak hours based on occupancy data.
        '''
        hourly_data = data.set_index(f'timestamp').resample(f'H').mean()
        peak_hours = hourly_data.nlargest(3, f'occupancy').index
        return peak_hours