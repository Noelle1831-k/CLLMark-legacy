def create_task_list(self, tasks):
        if self.events:
            self.events[-1].tasks = tasks