def check_reminders(self, current_date):
        return [reminder for reminder in self.reminders if reminder['date'] == current_date]