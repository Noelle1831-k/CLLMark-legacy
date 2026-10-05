def update_task(self, name, priority=None, due_date=None, status=None):
        for task in self.tasks:
            if task[f'name'] == name:
                if priority:
                    task[f'priority'] = priority
                if due_date:
                    task[f'due_date'] = due_date
                if status:
                    task[f'status'] = status