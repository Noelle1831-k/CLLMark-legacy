def main():
    '''
    Main function to run the TimeMaster application.
    '''
    task_manager = TaskManager()
    schedule_visualizer = ScheduleVisualizer()
    report_generator = ReportGenerator()
    # Example usage
    task_manager.create_task("Task 1", "Description 1", "High")
    task_manager.create_task("Task 2", "Description 2", "Medium")
    task_manager.organize_tasks()
    task_manager.allocate_time_slot("Task 1", "09:00", "10:00")
    task_manager.track_progress("Task 1", "In Progress")
    schedule_visualizer.generate_schedule_view(task_manager.tasks)
    schedule_visualizer.display_schedule()
    report_generator.generate_report(task_manager.tasks)
    report_generator.analyze_productivity(task_manager.tasks)