def optimize_itinerary(self, itinerary):
        '''
        Optimizes the itinerary by shuffling daily activities.
        Returns:
            list: A list of lists, where each sublist represents a day's activities.
        '''
        optimized = []
        for day_activities in itinerary:
            random.shuffle(day_activities)
            optimized.append(day_activities)
        return optimized