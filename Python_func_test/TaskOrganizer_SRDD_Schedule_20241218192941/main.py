def main():
    # Initialize components
    schedule = Schedule()
    reminder = Reminder()
    visualizer = Visualizer()
    # Sample tasks
    task1 = Task("Task 1", "Description 1", 1, "09:00-10:00", "Not Started")
    task2 = Task("Task 2", "Description 2", 2, "10:00-11:00", "In Progress")
    task3 = Task("Task 3", "Description 3", 3, "11:00-12:00", "Completed")
    # Add tasks to schedule
    schedule.add_task(task1)
    schedule.add_task(task2)
    schedule.add_task(task3)
    # Set reminders
    reminder.set_reminder(task1)
    reminder.set_reminder(task2)
    # Update task status
    schedule.update_task("Task 1", "In Progress")
    # Visualize schedule
    visualizer.display(schedule)
    # Notify reminders
    reminder.notify()