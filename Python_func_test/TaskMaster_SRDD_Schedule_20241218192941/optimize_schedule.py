def optimize_schedule(self):
        # Optimize schedule by sorting tasks based on priority and due date
        sorted_tasks = sorted(self.schedule.items(), key=lambda x: (x[1]['priority'], x[1]['due_date']))
        self.schedule = dict(sorted_tasks)