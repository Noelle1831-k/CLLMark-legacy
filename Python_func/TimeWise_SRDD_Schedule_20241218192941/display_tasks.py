def display_tasks(self):
        print("Current Tasks:")
        for task in self.tasks:
            print(f"Task: {task.name}, Priority: {task.priority}, Time: {task.time_allocated} mins, Progress: {task.progress}%")