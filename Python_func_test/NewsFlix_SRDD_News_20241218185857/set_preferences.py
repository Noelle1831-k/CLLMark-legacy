def set_preferences(self):
        '''
        Allows users to add or remove preferences.
        '''
        print("\n--- Set Preferences ---")
        while True:
            print("Current Preferences:", self.user_preferences.get_preferences())
            print("1. Add Preference")
            print("2. Remove Preference")
            print("3. Back")
            choice = input("Select an option (1-3): ")
            if choice == '1':
                topic = input("Enter a topic to add: ")
                self.user_preferences.add_preference(topic)
            elif choice == '2':
                topic = input("Enter a topic to remove: ")
                self.user_preferences.remove_preference(topic)
            elif choice == '3':
                break
            else:
                print("Invalid choice. Please try again.")