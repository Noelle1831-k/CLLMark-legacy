def update_task(self, task_id, task_name=None, due_date=None, priority=None):
        for task in self.tasks:
            if task['id'] == task_id:
                if task_name:
                    task['name'] = task_name
                if due_date:
                    task['due_date'] = datetime.strptime(due_date, '%Y-%m-%d')
                if priority:
                    task['priority'] = priority
                break