def main():
    logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
    logging.info("Starting the Office Deadline Reminder application.")
    task_manager = TaskManager()
    ui = UserInterface(task_manager)
    deadline_checker = DeadlineChecker(task_manager)
    ui.display_menu()
    deadline_checker.check_deadlines()