def update_task(self):
        '''
        Update an existing task via user input.
        '''
        task_id = input('Enter task ID to update: ')
        name = input('Enter new task name (leave blank to keep current): ')
        category = input('Enter new task category (leave blank to keep current): ')
        deadline = input('Enter new task deadline (YYYY-MM-DD, leave blank to keep current): ')
        completed = input('Mark as completed? (yes/no): ')
        kwargs = {}
        if name:
            kwargs['name'] = name
        if category:
            kwargs['category'] = category
        if deadline:
            kwargs['deadline'] = deadline
        if completed.lower() == 'yes':
            kwargs['completed'] = True
        self.task_manager.update_task(task_id, **kwargs)