def search_events(self, interest, location):
        events = self.db.get_events()
        results = [event for event in events if event.type == interest and event.location == location]
        print(f"Events found for {self.name}: {results}")