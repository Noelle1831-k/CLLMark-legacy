def handle_user_input(self, choice):
        if choice == '1':
            self.add_new_character()
        elif choice == '2':
            self.view_character()
        elif choice == '3':
            self.update_character()
        elif choice == '4':
            self.save_character_data()
        elif choice == '5':
            self.load_character_data()
        elif choice == '6':
            exit()
        else:
            print("Invalid choice. Please try again.")