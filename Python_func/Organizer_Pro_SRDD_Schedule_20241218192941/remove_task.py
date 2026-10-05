def remove_task(self):
        task_name = input("Enter task name to remove: ")
        self.tasks = [task for task in self.tasks if task['name'] != task_name]
        print("Task removed successfully.")