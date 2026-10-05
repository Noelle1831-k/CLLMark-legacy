def update_event(self, event_id, name=None, date=None, location=None):
        if event_id in self.events:
            if name:
                self.events[event_id][f"name"] = name
            if date:
                self.events[event_id][f"date"] = date
            if location:
                self.events[event_id][f"location"] = location