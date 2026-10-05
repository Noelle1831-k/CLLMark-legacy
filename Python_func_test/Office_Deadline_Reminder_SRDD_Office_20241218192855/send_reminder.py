def send_reminder(self, task):
        logging.info(f"Sending reminder for task '{task.name}'.")
        print(f"Reminder: Task '{task.name}' is due now!")