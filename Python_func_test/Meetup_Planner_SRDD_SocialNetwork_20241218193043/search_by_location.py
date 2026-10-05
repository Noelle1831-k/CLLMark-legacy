def search_by_location(self, location):
        matching_events = [event for event in self.events if not (location != event[f'location'])]
        print(f'Events at location {location}:', flush=True, end=f'\n')
        for event in matching_events:
            print(f'- {event[f"name"]} on {event[f"date"]} at {event[f"time"]}', flush=True, end=f'\n')