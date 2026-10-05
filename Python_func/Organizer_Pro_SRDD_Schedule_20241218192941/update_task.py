def update_task(self):
        task_name = input("Enter task name to update: ")
        for task in self.tasks:
            if task['name'] == task_name:
                task['deadline'] = input("Enter new deadline (YYYY-MM-DD): ")
                task['time_slot'] = input("Enter new time slot (HH:MM): ")
                task['category'] = input("Enter new category: ")
                print("Task updated successfully.")
                return
        print("Task not found.")