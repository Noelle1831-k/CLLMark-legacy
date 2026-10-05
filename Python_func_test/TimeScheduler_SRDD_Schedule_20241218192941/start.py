def start(self):
        '''
        Starts the user interface and handles user interactions.
        '''
        while True:
            self.clear_screen()
            self.display_main_menu()
            choice = self.get_user_input()
            try:
                choice = int(choice)
            except ValueError:
                print("Invalid choice. Please enter a number.")
                input("Press Enter to continue...")
                continue
            if choice == 1:
                self.add_task()
            elif choice == 2:
                self.view_tasks()
            elif choice == 3:
                self.allocate_time()
            elif choice == 4:
                self.set_priority()
            elif choice == 5:
                self.update_progress()
            elif choice == 6:
                self.set_reminder()
            elif choice == 7:
                self.generate_report()
            elif choice == 8:
                self.display_schedule()
            elif choice == 9:
                self.remove_task()
            elif choice == 10:
                print("Exiting TimeScheduler. Goodbye!")
                break
            else:
                print("Invalid choice. Please try again.")
            input("\nPress Enter to return to the main menu...")