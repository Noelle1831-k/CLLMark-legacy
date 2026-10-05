def analyze_productivity(self):
        completed_tasks = [task for task in self.tasks if task['status'] == 'Completed']
        total_tasks = len(self.tasks)
        total_time_allocated = sum(float(self.time_log[task['name']]['allocated'].split()[0]) for task in self.tasks if task['name'] in self.time_log)
        total_time_tracked = sum(self.time_log[task['name']]['tracked'] for task in self.tasks if task['name'] in self.time_log)
        if total_time_allocated > 0:
            efficiency = (total_time_tracked / total_time_allocated) * 100
        else:
            efficiency = 0
        self.productivity_data = {
            "efficiency": efficiency,
            "tasks_completed": len(completed_tasks),
            "total_tasks": total_tasks,
            "total_time_allocated": total_time_allocated,
            "total_time_tracked": total_time_tracked
        }