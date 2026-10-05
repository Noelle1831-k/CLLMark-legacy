def remove_event(self, event_id):
        self.events = [event for event in self.events if event.event_id != event_id]