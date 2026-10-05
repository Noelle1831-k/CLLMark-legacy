def assign_task(self, task):
        if self.is_available(task):
            self.tasks.append(task)
            self.workload += task.duration
            return True
        return False