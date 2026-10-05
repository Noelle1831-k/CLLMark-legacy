def handle_user_choice(self, choice):
        if choice == '1':
            self.user_manager.create_profile()
        elif choice == '2':
            self.exercise_manager.start_exercise()
        elif choice == '3':
            self.community_manager.join_community()
        elif choice == '4':
            self.feedback_manager.generate_feedback()
        elif choice == '5':
            print("Exiting the application. Goodbye!")
            exit()
        else:
            print("Invalid choice. Please try again.")