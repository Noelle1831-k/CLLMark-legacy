def update_task(self, task_title, new_task):
        for i, task in enumerate(self.tasks):
            if task.title == task_title:
                if any(self.time_manager.check_overlap(existing_task, new_task) for existing_task in self.tasks if existing_task.title != task_title):
                    print(f"Updated task '{new_task.title}' overlaps with existing tasks. Cannot update.")
                    return
                self.tasks[i] = new_task
                print(f"Task '{task_title}' updated.")
                return
        print(f"Task '{task_title}' not found.")