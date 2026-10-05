def create_task(self):
        task_name = input("Enter task name: ")
        task_description = input("Enter task description: ")
        task = {
            'name': task_name,
            'description': task_description,
            'status': 'Pending'
        }
        self.tasks.append(task)
        print(f"Task '{task_name}' created successfully.")