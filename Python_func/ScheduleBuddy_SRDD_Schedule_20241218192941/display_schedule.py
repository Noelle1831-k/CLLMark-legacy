def display_schedule(self):
        if not self.events:
            print("No events scheduled.")
            return
        for event in self.events:
            event.display_event()
            print("-" * 20)