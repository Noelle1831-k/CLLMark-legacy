def add_guest(self, event_id, name, email):
        if event_id not in self.guest_lists:
            self.guest_lists[event_id] = []
        self.guest_lists[event_id].append({"name": name, "email": email})