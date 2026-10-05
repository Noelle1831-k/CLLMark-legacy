def run(self):
        tasks = self.task_manager.get_tasks()
        analyzed_tasks = self.user_analyzer.analyze_user_behavior(tasks)
        for task in analyzed_tasks:
            priority = self.priority_algorithm.calculate_priority(task)
            if priority > 5:
                self.reminder.send_reminder(task)