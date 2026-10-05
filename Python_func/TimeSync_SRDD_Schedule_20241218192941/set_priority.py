def set_priority(self, task_id, priority):
        for task in self.schedule:
            if task['task_id'] == task_id:
                task['priority'] = priority
                print(f"Priority {priority} set for task ID {task_id}.")
                return
        print("Task ID not found in schedule.")