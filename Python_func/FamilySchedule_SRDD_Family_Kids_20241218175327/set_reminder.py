def set_reminder(self):
        '''
        Set the reminder to trigger at the specified time.
        '''
        if not self.is_set:
            delay = (self.reminder_time - datetime.datetime.now()).total_seconds()
            if delay > 0:
                self.scheduler.add_job(self.trigger_reminder, 'date', run_date=self.reminder_time)
                self.is_set = True
                print(f"Reminder set for {self.reminder_time}")
            else:
                print("Cannot set reminder for a past time.")
        else:
            print("Reminder is already set.")