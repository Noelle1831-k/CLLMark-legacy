def cancel_reminder(self):
        '''
        Cancel the reminder if it is set.
        '''
        if self.is_set:
            self.scheduler.remove_all_jobs()
            self.is_set = False
            print("Reminder cancelled.")
        else:
            print("No active reminder to cancel.")