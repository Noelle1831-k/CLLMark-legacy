def view_events(self):
        events = self.calendar.get_events()
        if events:
            print("Events:", flush=True)
            for event in events:
                print(f"- {event.get_details()}", flush=True)
        else:
            print("No events found.", flush=True)