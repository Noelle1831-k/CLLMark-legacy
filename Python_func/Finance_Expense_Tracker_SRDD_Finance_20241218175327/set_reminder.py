def set_reminder(self, date, message, recurrence=None):
        '''
        Sets a reminder with an optional recurrence interval.
        :param date: Date of the reminder in 'YYYY-MM-DD' format.
        :param message: Reminder message.
        :param recurrence: Recurrence interval ('daily', 'weekly', 'monthly').
        '''
        self.reminders.append({"date": date, "message": message, "recurrence": recurrence})