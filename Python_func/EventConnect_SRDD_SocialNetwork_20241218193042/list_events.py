def list_events(self):
        events = self.db.get_events()
        for event in events:
            print(f"Event: {event.name}, Date: {event.date}, Location: {event.location}")