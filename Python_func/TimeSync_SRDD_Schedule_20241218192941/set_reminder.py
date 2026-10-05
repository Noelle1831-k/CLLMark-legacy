def set_reminder(self):
        try:
            task_id = int(input("Enter task ID to set reminder: "))
            reminder_time = input("Enter reminder time: ")
            self.notifier.set_reminder(task_id, reminder_time)
        except ValueError:
            print("Invalid task ID. Please enter a numeric value.")