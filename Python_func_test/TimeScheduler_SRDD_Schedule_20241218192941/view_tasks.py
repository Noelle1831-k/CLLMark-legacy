def view_tasks(self):
        '''
        Displays all tasks in the system.
        '''
        print("\n--- Task List ---\n")
        self.task_manager.list_tasks()
        print("\n-----------------\n")