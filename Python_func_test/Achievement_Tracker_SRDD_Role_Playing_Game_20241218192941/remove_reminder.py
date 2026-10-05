def remove_reminder(self, achievement_name):
        if achievement_name in self.reminders:
            del self.reminders[achievement_name]