def send_invitation(self, event_id, email):
        if event_id not in self.rsvps:
            self.rsvps[event_id] = {}
        self.rsvps[event_id][email] = "Pending"