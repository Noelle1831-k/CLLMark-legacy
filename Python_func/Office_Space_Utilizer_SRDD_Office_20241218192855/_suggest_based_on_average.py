def _suggest_based_on_average(self, average_occupancy):
        '''
        Suggest actions based on average occupancy.
        '''
        if average_occupancy > 75:
            return "Consider expanding workspace."
        elif average_occupancy < 25:
            return "Consider reducing workspace."
        else:
            return "Current workspace is optimally utilized."