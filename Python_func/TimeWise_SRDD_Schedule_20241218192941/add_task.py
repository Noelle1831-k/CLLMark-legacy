def add_task(self, name, priority, time_allocated):
        task = Task(name, priority, time_allocated)
        self.tasks.append(task)
        print(f"Task '{name}' added with priority {priority} and time allocation of {time_allocated} mins.")