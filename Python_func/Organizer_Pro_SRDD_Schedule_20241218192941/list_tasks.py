def list_tasks(self):
        if not self.tasks:
            print("No tasks available.")
            return
        for task in self.tasks:
            print(f"Task: {task['name']}, Deadline: {task['deadline']}, Time Slot: {task['time_slot']}, Category: {task['category']}")