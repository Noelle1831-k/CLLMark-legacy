def generate_task_report(self):
        '''
        Prints a report of all tasks, their status, and the assigned employees.
        '''
        tasks = self.task_manager.get_tasks()
        print("\nTask Report:")
        print("-" * 50)
        for task in tasks:
            assigned_to = task.assigned_to or "None"
            print(f"Task ID: {task.id}, Description: {task.description}, Status: {task.status}, Assigned To: {assigned_to}")
        print("-" * 50)