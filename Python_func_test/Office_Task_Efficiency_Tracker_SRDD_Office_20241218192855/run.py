def run(self):
        '''
        Run the dashboard interface.
        '''
        while True:
            print("\nOffice Task Efficiency Tracker")
            print("1. Add Task")
            print("2. Update Task")
            print("3. Delete Task")
            print("4. View Tasks")
            print("5. Generate Report")
            print("6. Exit")
            choice = input("Enter your choice: ")
            if choice == '1':
                self.add_task()
            elif choice == '2':
                self.update_task()
            elif choice == '3':
                self.delete_task()
            elif choice == '4':
                self.view_tasks()
            elif choice == '5':
                self.generate_report()
            elif choice == '6':
                break
            else:
                print("Invalid choice. Please try again.")