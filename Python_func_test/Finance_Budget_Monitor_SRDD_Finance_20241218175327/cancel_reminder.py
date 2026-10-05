def cancel_reminder(self):
        for event in self.scheduler.queue:
            self.scheduler.cancel(event)
        print("Reminder cancelled.", flush=True)