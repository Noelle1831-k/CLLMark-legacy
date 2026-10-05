def start(self):
        while True:
            print("\nFinancial Progress Tracker")
            print("1. Add a new goal")
            print("2. Update an existing goal")
            print("3. Display all goals")
            print("4. Exit")
            choice = input("Enter your choice: ")
            if choice == '1':
                self.add_goal()
            elif choice == '2':
                self.update_goal()
            elif choice == '3':
                self.display_goals()
            elif choice == '4':
                print("Exiting the application.")
                break
            else:
                print("Invalid choice. Please try again.")