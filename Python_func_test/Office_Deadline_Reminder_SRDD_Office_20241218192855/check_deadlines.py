def check_deadlines(self):
        logging.info("Starting deadline check loop.")
        while True:
            for task in self.task_manager.get_tasks():
                if task.is_due():
                    self.reminder_service.send_reminder(task)
            time.sleep(60)  # Check every minute