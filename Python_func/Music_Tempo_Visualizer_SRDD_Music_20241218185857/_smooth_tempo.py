def _smooth_tempo(self, analyzed_data):
        '''
        Smoothes the tempo data to reduce sharp changes.
        '''
        smoothed_data = []
        for i in range(1, len(analyzed_data)):
            avg = (analyzed_data[i] + analyzed_data[i - 1]) / 2
            smoothed_data.append(avg)
        return smoothed_data