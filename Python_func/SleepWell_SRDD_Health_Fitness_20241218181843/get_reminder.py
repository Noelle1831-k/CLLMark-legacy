def get_reminder(self, user):
        return self.reminders.get(user.name, "No reminder set")