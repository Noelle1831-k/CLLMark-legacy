def handle_user_input(self, choice):
        if choice == '1':
            activity = input("Enter activity name: ")
            self.activity_manager.add_activity(activity)
        elif choice == '2':
            activity = input("Enter activity name to remove: ")
            self.activity_manager.remove_activity(activity)
        elif choice == '3':
            category = input("Enter category name: ")
            self.category_manager.add_category(category)
        elif choice == '4':
            category = input("Enter category name to remove: ")
            self.category_manager.remove_category(category)
        elif choice == '5':
            activity = input("Enter activity name: ")
            time = int(input("Enter time in minutes: "))
            self.time_allocator.allocate_time(activity, time)
        elif choice == '6':
            self.report_generator.generate_report()
        elif choice == '7':
            print("Exiting TimeTrack.")
            exit()
        else:
            print("Invalid choice. Please try again.")