def update_task(self):
        try:
            task_id = int(input("Enter task ID to update: "))
            new_details = input("Enter new task details: ")
            self.task_manager.update_task(task_id, new_details)
        except ValueError:
            print("Invalid task ID. Please enter a numeric value.")