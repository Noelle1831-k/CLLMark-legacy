def remove_event(self, event_name):
        # Remove an event
        if event_name in self.events:
            del self.events[event_name]