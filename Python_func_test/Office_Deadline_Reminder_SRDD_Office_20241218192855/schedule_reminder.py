def schedule_reminder(self, task):
        time_until_due = (task.deadline - datetime.now()).total_seconds()
        if time_until_due > 0:
            logging.info(f"Scheduling reminder for task '{task.name}' in {time_until_due} seconds.")
            time.sleep(time_until_due)
        self.send_reminder(task)