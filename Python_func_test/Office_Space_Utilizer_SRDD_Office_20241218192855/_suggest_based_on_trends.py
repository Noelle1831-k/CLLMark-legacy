def _suggest_based_on_trends(self, trends):
        '''
        Suggest actions based on occupancy trends.
        '''
        peak_hour = trends.idxmax()
        return f"Highest occupancy trend at hour: {peak_hour}. Consider optimizing resources during this time."