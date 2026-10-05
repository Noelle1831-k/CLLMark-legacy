def add_task(self, task_name, due_date, priority):
        task_id = len(self.tasks) + 1
        # Convert due_date to a datetime object
        due_date_obj = datetime.strptime(due_date, '%Y-%m-%d')
        task = {'id': task_id, 'name': task_name, 'due_date': due_date_obj, 'priority': priority}
        self.tasks.append(task)