def main():
    '''
    Initializes the TaskManager and UI, and starts the application.
    '''
    task_manager = TaskManager()
    ui = UI(task_manager)
    ui.display_menu()