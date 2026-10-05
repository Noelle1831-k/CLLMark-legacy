def add_task(self):
        task_name = input("Enter task name: ")
        task_details = input("Enter task details: ")
        self.task_manager.add_task(task_name, task_details)