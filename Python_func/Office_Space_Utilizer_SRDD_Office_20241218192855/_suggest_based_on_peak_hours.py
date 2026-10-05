def _suggest_based_on_peak_hours(self, peak_hours):
        '''
        Suggest actions based on peak hours.
        '''
        return f"Peak hours identified: {', '.join(map(str, peak_hours))}. Consider flexible scheduling."