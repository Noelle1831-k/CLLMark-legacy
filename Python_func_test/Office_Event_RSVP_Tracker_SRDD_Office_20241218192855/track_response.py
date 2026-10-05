def track_response(self, event_id, email, response):
        if event_id in self.rsvps and email in self.rsvps[event_id]:
            self.rsvps[event_id][email] = response