def receive_notifications(self):
        for challenge in self.challenges:
            challenge.send_reminders()