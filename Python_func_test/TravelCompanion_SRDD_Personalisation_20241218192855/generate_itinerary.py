def generate_itinerary(self):
        itinerary_details = []
        for destination in self.destinations:
            itinerary_details.append(destination.get_info())
        return itinerary_details