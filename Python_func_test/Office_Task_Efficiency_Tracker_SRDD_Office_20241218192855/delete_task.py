def delete_task(self):
        '''
        Delete a task via user input.
        '''
        task_id = input("Enter task ID to delete: ")
        self.task_manager.delete_task(task_id)