def create_event(self, name, date, location):
        event_id = len(self.events) + 1
        self.events[event_id] = {"name": name, "date": date, "location": location}
        return event_id