def display_menu(self):
        while True:
            print("\nFinancial Goal Manager")
            print("1. Add Goal")
            print("2. Update Goal")
            print("3. Delete Goal")
            print("4. List Goals")
            print("5. Track Progress")
            print("6. Get Advice")
            print("7. Exit")
            choice = input("Choose an option: ")
            if choice == '1':
                self.add_goal()
            elif choice == '2':
                self.update_goal()
            elif choice == '3':
                self.delete_goal()
            elif choice == '4':
                self.list_goals()
            elif choice == '5':
                self.track_progress()
            elif choice == '6':
                self.get_advice()
            elif choice == '7':
                break
            else:
                print("Invalid choice. Please try again.")