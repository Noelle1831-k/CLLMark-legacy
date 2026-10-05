def filter_destinations(self, user_preferences, destinations):
        return [destination for destination in destinations if destination.calculate_affinity(user_preferences) > 0]