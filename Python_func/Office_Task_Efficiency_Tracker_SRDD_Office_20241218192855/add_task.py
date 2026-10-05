def add_task(self):
        '''
        Add a new task via user input.
        '''
        name = input("Enter task name: ")
        category = input("Enter task category: ")
        deadline = input("Enter task deadline (YYYY-MM-DD): ")
        self.task_manager.add_task(name, category, deadline)