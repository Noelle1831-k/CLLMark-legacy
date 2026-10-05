def set(self):
        event_time = time.mktime(time.strptime(self.reminder_time, "%Y-%m-%d %H:%M:%S"))
        self.scheduler.enterabs(event_time, 1, self.remind)
        threading.Thread(target=self.scheduler.run).start()