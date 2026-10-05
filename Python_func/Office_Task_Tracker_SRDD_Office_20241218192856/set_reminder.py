def set_reminder(self, task_id, reminder_time):
        '''
        Sets a reminder for a specific task.
        '''
        task = self.tasks[task_id]
        self.reminder.add_reminder(task, reminder_time)