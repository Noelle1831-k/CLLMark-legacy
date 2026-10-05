def view_tasks(self):
        '''
        Display all tasks.
        '''
        tasks = self.task_manager.get_all_tasks()
        for task in tasks:
            print(f"ID: {task.id}, Name: {task.name}, Category: {task.category}, Deadline: {task.deadline}, Time Spent: {task.time_spent}, Completed: {task.completed}")