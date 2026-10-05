def list_tasks(self):
        """
        Lists all tasks currently added for visualization.
        """
        if not self.tasks:
            print("No tasks available.")
            return
        print("\n--- Scheduled Tasks ---")
        for idx, task in enumerate(self.tasks, 1):
            start = task['start_time'].strftime("%H:%M")
            end = task['end_time'].strftime("%H:%M")
            print(f"{idx}. {task['name']} | {start} - {end}")
        print("------------------------")