def track_rsvps(self):
        if self.events:
            for attendee in self.events[-1].attendees:
                attendee.rsvp_status = random.choice(["Accepted", "Declined", "Pending"])