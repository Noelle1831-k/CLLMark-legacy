def send_notification(self):
        print("Sending notifications for upcoming tasks...", flush=True)
        current_time = datetime.now()
        for task_name, reminder_time in self.reminders.items():
            if current_time >= reminder_time:
                print(f"Reminder: Task '{task_name}' is due!", flush=True)
                del self.reminders[task_name]
                break
        time.sleep(60)  # Check every minute