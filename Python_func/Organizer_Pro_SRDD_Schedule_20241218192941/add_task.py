def add_task(self):
        task_name = input("Enter task name: ")
        deadline = input("Enter deadline (YYYY-MM-DD): ")
        time_slot = input("Enter time slot (HH:MM): ")
        category = input("Enter category: ")
        task = {
            'name': task_name,
            'deadline': deadline,
            'time_slot': time_slot,
            'category': category
        }
        self.tasks.append(task)
        print("Task added successfully.")