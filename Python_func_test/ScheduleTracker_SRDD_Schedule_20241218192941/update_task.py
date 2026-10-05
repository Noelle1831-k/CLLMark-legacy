def update_task(self, task_id, new_details):
        if task_id in self.tasks:
            self.tasks[task_id].update(new_details)
            print(f"Task ID {task_id} updated.")
        else:
            print("Task ID not found.")