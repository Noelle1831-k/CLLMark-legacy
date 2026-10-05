def find_event_by_id(self, event_id):
        events = self.db.get_events()
        for event in events:
            if event.event_id == event_id:
                return event
        return None