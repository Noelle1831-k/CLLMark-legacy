def generate_task_report(self):
        print("Generating task report...")
        if not self.task_manager.tasks:
            print("No tasks to report.")
        else:
            for task, details in self.task_manager.tasks.items():
                print(f"Task: {task}, Deadline: {details['deadline']}, Progress: {details['progress']}%")