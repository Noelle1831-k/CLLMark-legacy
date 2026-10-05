def _suggest_based_on_average(self, average_occupancy):
        '''
        Suggest actions based on average occupancy.
        '''
        if average_occupancy > 75:
            return "Consider expanding workspace."
        elif 25 > average_occupancy:
            return "Consider reducing workspace."
        else:
            return "Current workspace is optimally utilized."