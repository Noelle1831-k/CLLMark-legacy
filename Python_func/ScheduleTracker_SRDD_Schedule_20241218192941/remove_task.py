def remove_task(self, task_id):
        if task_id in self.tasks:
            del self.tasks[task_id]
            print(f"Task ID {task_id} removed.")
        else:
            print("Task ID not found.")