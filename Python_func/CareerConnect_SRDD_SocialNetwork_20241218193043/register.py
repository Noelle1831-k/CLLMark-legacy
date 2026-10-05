def register(self, user):
        self.attendees.append(user)
        print(f"{user.name} registered for {self.name}")