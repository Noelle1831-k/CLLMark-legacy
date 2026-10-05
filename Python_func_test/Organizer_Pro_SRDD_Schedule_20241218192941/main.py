def main():
    ui = UserInterface()
    task_manager = TaskManager()
    visualizer = ScheduleVisualizer(task_manager)
    reminder_system = ReminderSystem(task_manager)
    report_generator = ReportGenerator(task_manager)
    while True:
        ui.display_menu()
        choice = ui.get_user_input()
        if choice == '1':
            task_manager.add_task()
        elif choice == '2':
            task_manager.remove_task()
        elif choice == '3':
            task_manager.update_task()
        elif choice == '4':
            task_manager.list_tasks()
        elif choice == '5':
            visualizer.generate_calendar_view()
        elif choice == '6':
            visualizer.generate_list_view()
        elif choice == '7':
            reminder_system.set_reminder()
        elif choice == '8':
            report_generator.generate_report()
        elif choice == '9':
            break
        else:
            print("Invalid choice. Please try again.")