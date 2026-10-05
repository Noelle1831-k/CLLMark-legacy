def get_user_input(self):
        choice = input("Enter your choice: ").strip().lower()
        # Map numeric input to corresponding string command
        if choice == '1':
            return 'meditation'
        elif choice == '2':
            return 'breathing'
        elif choice == '3':
            return 'activity'
        elif choice == '4':
            return 'game'
        elif choice == 'exit':
            return 'exit'
        else:
            print("Invalid choice, please try again.")
            return None