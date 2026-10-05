def main():
    dashboard = Dashboard()
    # Creating users
    user1 = User("Alice", "alice@example.com")
    user2 = User("Bob", "bob@example.com")
    # Adding users to the dashboard
    dashboard.add_user(user1)
    dashboard.add_user(user2)
    # Creating tasks and assigning them to users
    task1 = Task("Design Homepage", "Design the homepage of the website", user1, "2023-12-01", "High", "Pending")
    task2 = Task("Develop Backend", "Develop the backend of the application", user2, "2023-12-15", "Medium", "Pending")
    # Adding tasks to the dashboard and assigning them to users' task lists
    dashboard.create_task(task1)
    dashboard.create_task(task2)
    # Viewing all tasks on the dashboard
    dashboard.view_all_tasks()
    # Users viewing their assigned tasks
    user1.view_tasks()
    user2.view_tasks()
    # User communication
    user1.communicate(user2, "Please review the homepage design.")
    # Updating task status and priority
    task1.update_status("In Progress")
    task2.update_priority("High")
    # Sending notifications to users
    dashboard.notify_users(task1)
    dashboard.notify_users(task2)