def set_reminder(self):
        task_name = input("Enter task name to set reminder: ")
        reminder_time = input("Enter reminder time (HH:MM): ")
        for task in self.task_manager.tasks:
            if task['name'] == task_name:
                reminder_datetime = datetime.strptime(task['deadline'] + ' ' + reminder_time, '%Y-%m-%d %H:%M')
                self.reminders[task_name] = reminder_datetime
                print(f"Reminder set for task '{task_name}' at {reminder_time}.")
                return
        print("Task not found.")