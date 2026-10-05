def send_reminder(self, event_id):
        if event_id in self.rsvps:
            for email, status in self.rsvps[event_id].items():
                if status == "Pending":
                    print(f"Reminder sent to {email}")