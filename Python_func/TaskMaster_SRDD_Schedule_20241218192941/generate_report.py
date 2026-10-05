def generate_report(self, tasks):
        # Generate a detailed productivity report
        completed_tasks = [task for task in tasks if task['completed']]
        pending_tasks = [task for task in tasks if not task['completed']]
        report = f"Productivity Report:\nCompleted Tasks: {len(completed_tasks)}\nPending Tasks: {len(pending_tasks)}"
        self.reports.append(report)
        print(report)