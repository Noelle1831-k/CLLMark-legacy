def schedule_notification(self, task):
        '''
        Schedules a notification for a task.
        '''
        task_time = datetime.strptime(task.time_slot, "%I:%M %p")
        current_time = datetime.now()
        if task_time < current_time:
            task_time += timedelta(days=1)  # Schedule for the next day if time has passed
        self.scheduler.add_job(
            self.notify,
            'date',
            run_date=task_time,
            args=[task]
        )
        print(f"Reminder set for task: {task.name} at {task.time_slot}")