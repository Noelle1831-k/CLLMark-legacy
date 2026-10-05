def add_task(self):
        task = input("Enter your task: ")
        self.tasks.append(task)
        print("Task added successfully.")