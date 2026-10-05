def rsvp_event(self, event):
        event.add_attendee(self)
        print(f"{self.name} RSVP'd to {event.name}")