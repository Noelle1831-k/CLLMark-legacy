def generate_overview(self, tasks, schedule):
        # Generate a detailed visual overview based on tasks and their schedule
        self.overview = [
            f"Task: {task['name']}, Priority: {task['priority']}, Scheduled: {schedule.get(task['name'], {}).get('start_time', 'Not Scheduled')} - {schedule.get(task['name'], {}).get('end_time', 'Not Scheduled')}"
            for task in tasks
        ]