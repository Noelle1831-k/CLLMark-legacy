def check_reminders(self):
        '''
        Checks for due reminders and returns them.
        '''
        due_reminders = []
        now = datetime.datetime.now()
        for task, reminder_time in self.reminders:
            if now >= reminder_time and not task.completed:
                due_reminders.append(task)
        return due_reminders