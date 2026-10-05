def generate_report(self, tasks):
        print("Productivity Report:")
        for task in tasks:
            print(f"Task: {task.name}, Time Spent: {task.time_allocated} mins, Progress: {task.progress}%")
        print("End of Report.")