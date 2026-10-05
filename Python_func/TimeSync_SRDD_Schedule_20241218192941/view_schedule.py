def view_schedule(self):
        schedule = self.scheduler.get_schedule()
        for task in schedule:
            print(task)