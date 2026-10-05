def set_priority(self, task_name, priority):
        if task_name in self.schedule:
            self.schedule[task_name]['priority'] = priority