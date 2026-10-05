def is_available(self, task):
        return self.availability >= self.workload + task.duration