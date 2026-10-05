def plan_itinerary(self, user_preferences, destinations):
        itinerary = Itinerary()
        filtered_destinations = self.filter_destinations(user_preferences, destinations)
        sorted_destinations = self.sort_destinations(filtered_destinations, user_preferences)
        for destination in sorted_destinations:
            if itinerary.total_cost + destination.cost <= user_preferences.budget:
                itinerary.add_destination(destination)
        return itinerary