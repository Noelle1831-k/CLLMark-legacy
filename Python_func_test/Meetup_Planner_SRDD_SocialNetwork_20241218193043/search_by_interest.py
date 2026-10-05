def search_by_interest(self, interest):
        matching_events = [event for event in self.events if interest in event['interests']]
        print(f"Events matching interest {interest}:")
        for event in matching_events:
            print(f"- {event['name']} at {event['location']} on {event['date']}")