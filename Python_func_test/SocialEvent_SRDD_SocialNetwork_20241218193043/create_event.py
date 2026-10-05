def create_event(self, title, location, date):
        event = Event(title, location, date)
        self.events.append(event)
        return event