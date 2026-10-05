def set_reminders(self, tasks):
        '''
        Sets reminders for tasks.
        '''
        for task in tasks:
            self.schedule_notification(task)