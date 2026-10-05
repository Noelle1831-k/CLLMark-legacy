def handle_user_input(self, choice):
        try:
            if choice == '1':
                name = input("Enter task name: ")
                description = input("Enter task description: ")
                deadline = input("Enter deadline (YYYY-MM-DD HH:MM:SS): ")
                self.task_manager.add_task(name, description, deadline)
            elif choice == '2':
                name = input("Enter task name to remove: ")
                self.task_manager.remove_task(name)
            elif choice == '3':
                name = input("Enter task name to update deadline: ")
                new_deadline = input("Enter new deadline (YYYY-MM-DD HH:MM:SS): ")
                self.task_manager.update_task_deadline(name, new_deadline)
            elif choice == '4':
                tasks = self.task_manager.get_tasks()
                for task in tasks:
                    print(f"Task: {task.name}, Description: {task.description}, Deadline: {task.deadline}, Status: {task.status}")
            elif choice == '5':
                logging.info("Exiting application.")
                print("Exiting...")
                exit()
            else:
                logging.warning("Invalid choice entered.")
                print("Invalid choice. Please try again.")
        except Exception as e:
            logging.error(f"Error handling user input: {e}")
            print("An error occurred. Please try again.")