def remove_guest(self, event_id, email):
        if event_id in self.guest_lists:
            self.guest_lists[event_id] = [guest for guest in self.guest_lists[event_id] if guest["email"] != email]