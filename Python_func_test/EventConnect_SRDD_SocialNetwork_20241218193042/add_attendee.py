def add_attendee(self, user):
        self.attendees.append(user)
        print(f"Added {user.name} to {self.name}")