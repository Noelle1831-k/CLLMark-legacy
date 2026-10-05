def run(self):
        print("Welcome to Family Schedule App!")
        while True:
            print("\nMenu:")
            print("1. Add Family Member")
            print("2. Add Task")
            print("3. Add Event")
            print("4. Add Reminder")
            print("5. View Family Members")
            print("6. View Tasks")
            print("7. View Events")
            print("8. View Reminders")
            print("9. Exit")
            choice = input("Enter your choice: ")
            if choice == '1':
                self.add_family_member()
            elif choice == '2':
                self.add_task()
            elif choice == '3':
                self.add_event()
            elif choice == '4':
                self.add_reminder()
            elif choice == '5':
                self.view_family_members()
            elif choice == '6':
                self.view_tasks()
            elif choice == '7':
                self.view_events()
            elif choice == '8':
                self.view_reminders()
            elif choice == '9':
                print("Exiting Family Schedule App. Goodbye!")
                sys.exit()
            else:
                print("Invalid choice. Please try again.")