def check_reminders(self):
        current_time = datetime.datetime.now().strftime("%Y-%m-%d %H:%M")
        for task_name, reminder_time in self.reminders.items():
            if reminder_time <= current_time:
                print(f"Reminder: It's time to work on '{task_name}'!")
            else:
                print(f"No reminders due at the moment for '{task_name}'.")