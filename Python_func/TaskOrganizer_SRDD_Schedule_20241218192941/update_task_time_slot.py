def update_task_time_slot(self, task_title, new_time_slot):
        for task in self.tasks:
            if task.title == task_title:
                task.update_time_slot(new_time_slot)