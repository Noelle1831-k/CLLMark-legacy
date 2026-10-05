def invite_attendees(self, emails):
        if self.events:
            for email in emails:
                attendee = Attendee(email)
                self.events[-1].attendees.append(attendee)
                self.send_email(email, "Invitation", f"You are invited to {self.events[-1].name}.")