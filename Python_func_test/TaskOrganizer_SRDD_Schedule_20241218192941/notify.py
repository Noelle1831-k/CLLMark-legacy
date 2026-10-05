def notify(self):
        current_time = time.strftime("%H:%M")
        for task_title, time_slot in self.reminders.items():
            if current_time in time_slot:
                print(f"Reminder: It's time for {task_title}")