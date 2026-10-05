def display_menu(self):
        while True:
            print("\nOffice Deadline Reminder")
            print("1. Add Task")
            print("2. Remove Task")
            print("3. Update Task Deadline")
            print("4. View Tasks")
            print("5. Exit")
            choice = input("Enter your choice: ")
            self.handle_user_input(choice)