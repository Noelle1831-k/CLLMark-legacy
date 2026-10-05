def rsvp(self, user):
        if user not in self.attendees:
            self.attendees.append(user)
            user.join_event(self)