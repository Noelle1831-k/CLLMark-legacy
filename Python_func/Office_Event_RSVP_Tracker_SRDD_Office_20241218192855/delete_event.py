def delete_event(self, event_id):
        if event_id in self.events:
            del self.events[event_id]