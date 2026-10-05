def search_by_location(self, location):
        matching_events = [event for event in self.events if event['location'] == location]
        print(f"Events at location {location}:")
        for event in matching_events:
            print(f"- {event['name']} on {event['date']} at {event['time']}")