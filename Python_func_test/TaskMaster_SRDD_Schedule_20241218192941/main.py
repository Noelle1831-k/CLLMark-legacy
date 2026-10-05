def main():
    # Initialize TaskManager and add tasks
    task_manager = TaskManager()
    task_manager.add_task("Complete project report", "2023-10-15", "High")
    task_manager.add_task("Prepare presentation", "2023-10-20", "Medium")
    task_manager.add_task("Team meeting", "2023-10-18", "Low")
    # Initialize Scheduler with tasks from TaskManager
    scheduler = Scheduler(task_manager.list_tasks())
    notifier = Notifier()
    report_generator = ReportGenerator()
    visualizer = Visualizer()
    # Allocate time and optimize schedule
    scheduler.allocate_time()
    scheduler.optimize_schedule()
    # Set reminders and send notifications
    notifier.set_reminder("Complete project report", "2023-10-14 09:00")
    notifier.set_reminder("Prepare presentation", "2023-10-19 15:00")
    notifier.send_notification()
    # Generate report and display schedule
    report_generator.generate_report(task_manager.list_tasks())
    visualizer.display_schedule(scheduler.get_schedule())