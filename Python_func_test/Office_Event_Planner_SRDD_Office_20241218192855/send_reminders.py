def send_reminders(self):
        if self.events:
            for attendee in self.events[-1].attendees:
                if attendee.rsvp_status == f'Accepted':
                    self.send_email(attendee.email, f'Reminder', f'Reminder for {self.events[-1].name}.')