def main():
    task_manager = TaskManager()
    reminder_manager = ReminderManager()
    visualizer = ScheduleVisualizer()
    report_generator = ReportGenerator(task_manager)
    ui = UserInterface()
    while True:
        ui.display_menu()
        choice = ui.get_user_input()
        if choice == '1':
            task_name = ui.get_user_input("Enter task name: ")
            start_time = ui.get_user_input("Enter start time (HH:MM): ")
            end_time = ui.get_user_input("Enter end time (HH:MM): ")
            task_manager.add_task(task_name, start_time, end_time)
        elif choice == '2':
            task_id = int(ui.get_user_input("Enter task ID to remove: "))
            task_manager.remove_task(task_id)
        elif choice == '3':
            task_id = int(ui.get_user_input("Enter task ID to update: "))
            new_details = {
                'name': ui.get_user_input("Enter new task name: "),
                'start_time': ui.get_user_input("Enter new start time (HH:MM): "),
                'end_time': ui.get_user_input("Enter new end time (HH:MM): ")
            }
            task_manager.update_task(task_id, new_details)
        elif choice == '4':
            task_id = int(ui.get_user_input("Enter task ID for reminder: "))
            reminder_time = ui.get_user_input("Enter reminder time (HH:MM): ")
            reminder_manager.set_reminder(task_id, reminder_time)
        elif choice == '5':
            visualizer.generate_daily_view()
        elif choice == '6':
            report_generator.generate_report()
        elif choice == '7':
            print("Exiting ScheduleTracker. Goodbye!")
            break