def input_events(self):
        events = input("List any significant events today (comma-separated): ")
        self.events = [event.strip() for event in events.split(',')]
        return self.events