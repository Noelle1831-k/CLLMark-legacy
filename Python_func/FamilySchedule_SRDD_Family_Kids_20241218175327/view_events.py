def view_events(self):
        events = self.calendar.get_events()
        if events:
            print("Events:")
            for event in events:
                print(f"- {event.get_details()}")
        else:
            print("No events found.")