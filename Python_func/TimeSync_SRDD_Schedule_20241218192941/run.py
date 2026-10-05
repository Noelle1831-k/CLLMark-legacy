def run(self):
        while True:
            self.display_menu()
            choice = input("Enter your choice: ")
            if choice == '1':
                self.add_task()
            elif choice == '2':
                self.remove_task()
            elif choice == '3':
                self.update_task()
            elif choice == '4':
                self.view_schedule()
            elif choice == '5':
                self.sync_tasks()
            elif choice == '6':
                self.set_reminder()
            elif choice == '7':
                self.generate_report()
            elif choice == '8':
                break
            else:
                print("Invalid choice. Please try again.")