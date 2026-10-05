def process_input(self, choice):
        '''
        Processes the user's menu choice and calls the appropriate method.
        '''
        if choice == '1':
            self.add_skill()
        elif choice == '2':
            self.remove_skill()
        elif choice == '3':
            self.view_skill_tree()
        elif choice == '4':
            self.upgrade_skill()
        elif choice == '5':
            self.downgrade_skill()
        elif choice == '6':
            print("Exiting the application. Goodbye!")
            exit()
        else:
            print("Invalid choice. Please try again.")