def main():
    task_manager = TaskManager()
    habit_tracker = HabitTracker()
    goal_setter = GoalSetter()
    report_generator = ReportGenerator(task_manager, habit_tracker, goal_setter)
    while True:
        print("\nChoose an action:")
        print("1. Create Task")
        print("2. Add Habit")
        print("3. Set Goal")
        print("4. Track Task Progress")
        print("5. Track Habit Progress")
        print("6. Track Goal Progress")
        print("7. Generate Reports")
        print("8. Exit")
        choice = input("Enter your choice: ")
        if choice == '1':
            name = input("Enter task name: ")
            deadline = input("Enter deadline (YYYY-MM-DD): ")
            task_manager.create_task(name, deadline)
        elif choice == '2':
            name = input("Enter habit name: ")
            habit_tracker.add_habit(name)
        elif choice == '3':
            name = input("Enter goal name: ")
            goal_setter.set_goal(name)
        elif choice == '4':
            name = input("Enter task name to track: ")
            task_manager.track_progress(name)
        elif choice == '5':
            name = input("Enter habit name to track: ")
            habit_tracker.track_habit(name)
        elif choice == '6':
            name = input("Enter goal name to track: ")
            goal_setter.track_goal(name)
        elif choice == '7':
            report_generator.generate_task_report()
            report_generator.generate_habit_report()
            report_generator.generate_goal_report()
        elif choice == '8':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please try again.")