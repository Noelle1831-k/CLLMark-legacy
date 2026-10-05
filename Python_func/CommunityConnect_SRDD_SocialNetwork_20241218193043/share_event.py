def share_event(self, user, event_details):
        self.event_service.add_event(user, event_details)