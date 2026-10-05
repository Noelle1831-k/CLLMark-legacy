def create_event(self, name, date, location):
        event = Event(name, date, location)
        self.events.append(event)