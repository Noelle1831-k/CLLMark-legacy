def sort_destinations(self, destinations, user_preferences):
        return sorted(destinations, key=lambda d: (d.calculate_affinity(user_preferences), d.rating), reverse=True)