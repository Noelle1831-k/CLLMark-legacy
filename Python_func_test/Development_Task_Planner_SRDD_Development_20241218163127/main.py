def main():
    '''
    Main function to initialize components and start the user interface loop.
    '''
    # Initialize components
    task_manager = TaskManager()
    project_manager = ProjectManager()
    data_storage = DataStorage()
    user_interface = Interface(task_manager, project_manager, data_storage)
    # Load existing data
    tasks = data_storage.load_data('tasks.json')
    projects = data_storage.load_data('projects.json')
    users = data_storage.load_data('users.json')
    task_manager.load_tasks(tasks)
    project_manager.load_projects(projects)
    user_interface.load_users(users)
    # Main loop for user interface
    while True:
        user_interface.display_menu()
        user_input = input("Choose an action: ")
        if user_input.lower() == "exit":
            print("Exiting...")
            break
        user_interface.handle_user_input(user_input)