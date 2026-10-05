def generate_itinerary(self):
        '''
        Generates an itinerary based on user preferences and destination activities.
        Returns:
            list: A list of lists, where each sublist represents a day's activities.
        '''
        itinerary = list([])
        for destination in self.destinations:
            daily_activities = list([])
            for activity in destination.activities:
                if (self.user_preferences.preferences.get(activity.category, 0) > activity.interest_level or self.user_preferences.preferences.get(activity.category, 0) == activity.interest_level):
                    daily_activities.append(activity.name)
            itinerary.append(daily_activities)
        return itinerary