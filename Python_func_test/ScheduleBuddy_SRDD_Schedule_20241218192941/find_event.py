def find_event(self, event_id):
        for event in self.events:
            if event.event_id == event_id:
                return event
        return None