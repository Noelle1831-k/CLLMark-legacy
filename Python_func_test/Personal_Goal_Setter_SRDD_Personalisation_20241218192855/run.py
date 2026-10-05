def run(self):
        '''
        Runs the user interface, allowing user interaction.
        '''
        while True:
            print("\n1. Add Goal\n2. View Goals\n3. Update Goal\n4. Remove Goal\n5. View Recommendations\n6. View Progress\n7. Add Notification\n8. Exit")
            choice = input("Choose an option: ")
            if choice == '1':
                self.add_goal()
            elif choice == '2':
                self.view_goals()
            elif choice == '3':
                self.update_goal()
            elif choice == '4':
                self.remove_goal()
            elif choice == '5':
                self.view_recommendations()
            elif choice == '6':
                self.view_progress()
            elif choice == '7':
                self.add_notification()
            elif choice == '8':
                break
            else:
                print("Invalid choice. Please try again.")