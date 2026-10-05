def main():
    task_manager = TaskManager()
    category_manager = CategoryManager()
    scheduler = Scheduler()
    notification_manager = NotificationManager()
    user_interface = UserInterface(task_manager, category_manager, scheduler, notification_manager)
    while True:
        user_interface.display_tasks()
        user_input = user_interface.get_user_input()
        if user_input == 'exit':
            print("Exiting TaskArranger. Goodbye!")
            break
        elif user_input == 'add':
            task = input("Enter task to add: ")
            task_manager.add_task(task)
        elif user_input == 'remove':
            task = input("Enter task to remove: ")
            task_manager.remove_task(task)
        elif user_input == 'update':
            old_task = input("Enter task to update: ")
            new_task = input("Enter new task: ")
            task_manager.update_task(old_task, new_task)
        elif user_input == 'category':
            category_manager.list_categories()
            category_action = input("Enter 'add' to add category or 'remove' to remove category: ")
            category = input("Enter category: ")
            if category_action == 'add':
                category_manager.add_category(category)
            elif category_action == 'remove':
                category_manager.remove_category(category)
        elif user_input == 'schedule':
            task = input("Enter task to schedule: ")
            time_slot = input("Enter time slot: ")
            scheduler.allocate_time_slot(task, time_slot)
            scheduler.view_schedule()
        elif user_input == 'reminder':
            task = input("Enter task to set reminder for: ")
            reminder_time = input("Enter reminder time: ")
            notification_manager.set_reminder(task, reminder_time)
            notification_manager.send_notification(task)
        else:
            print("Invalid option. Please try again.")