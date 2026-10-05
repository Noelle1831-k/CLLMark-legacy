def list_guests(self, event_id):
        return self.guest_lists.get(event_id, [])