def update_task(self, name, priority=None, due_date=None, status=None):
        for task in self.tasks:
            if task['name'] == name:
                if priority:
                    task['priority'] = priority
                if due_date:
                    task['due_date'] = due_date
                if status:
                    task['status'] = status