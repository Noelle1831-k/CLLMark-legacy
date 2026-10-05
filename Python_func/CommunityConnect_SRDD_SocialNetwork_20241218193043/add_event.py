def add_event(self, user, event_details):
        event = {"user": user.username, "details": event_details}
        self.events.append(event)
        print(f"Event added by {user.username}: {event_details}")