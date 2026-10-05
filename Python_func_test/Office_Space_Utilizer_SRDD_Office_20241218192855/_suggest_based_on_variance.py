def _suggest_based_on_variance(self, variance):
        '''
        Suggest actions based on occupancy variance.
        '''
        if variance > 50:
            return "High variance detected. Consider dynamic workspace allocation."
        else:
            return "Low variance detected. Current allocation is stable."