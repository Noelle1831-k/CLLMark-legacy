def send_reminder(self):
        for goal in self.goals:
            reminder = Reminder(goal)
            reminder.schedule_reminder()