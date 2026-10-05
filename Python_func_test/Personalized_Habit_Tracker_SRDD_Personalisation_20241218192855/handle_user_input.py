def handle_user_input(self):
        '''
        Handle user input and perform actions.
        '''
        choice = input("Enter your choice: ")
        if choice == '1':
            habit_name = input("Enter habit name: ")
            frequency = int(input("Enter frequency: "))
            self.habit_tracker.add_habit(habit_name, frequency)
        elif choice == '2':
            habit_name = input("Enter habit name to remove: ")
            self.habit_tracker.remove_habit(habit_name)
        elif choice == '3':
            habit_name = input("Enter habit name to update: ")
            frequency = int(input("Enter new frequency: "))
            self.habit_tracker.update_habit(habit_name, frequency)
        elif choice == '4':
            habit_name = input("Enter habit name to log activity: ")
            self.habit_monitor.log_activity(habit_name)
        elif choice == '5':
            print(self.habit_tracker.get_habits())
        elif choice == '6':
            self.recommendation_engine.analyze_habits(self.habit_tracker.get_habits())
            print(self.recommendation_engine.generate_recommendations())
        elif choice == '7':
            exit()
        else:
            print("Invalid choice. Please try again.")