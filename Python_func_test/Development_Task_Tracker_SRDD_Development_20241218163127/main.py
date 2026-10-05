def main():
    '''
    Initializes managers and demonstrates example usage of the application.
    '''
    task_manager = TaskManager()
    user_manager = UserManager()
    project_manager = ProjectManager()
    notification_manager = NotificationManager()
    # Example usage
    user_id = user_manager.create_user("Alice", "alice@example.com")
    project_id = project_manager.create_project("Project A")
    task_id = task_manager.create_task("Task 1", "Description of Task 1", "High", "2023-12-31", [], "Open")
    project_manager.add_member(project_id, user_id)
    task_manager.assign_task(task_id, user_id)
    notification_id = notification_manager.create_notification("Task 1 assigned to you", user_id)
    notification_manager.send_notification(notification_id)