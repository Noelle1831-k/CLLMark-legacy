def main_menu(self):
        while True:
            print("1. Add Event")
            print("2. Remove Event")
            print("3. View Schedule")
            print("4. Exit")
            choice = input("Choose an option: ")
            if choice == '1':
                self.add_event_ui()
            elif choice == '2':
                self.remove_event_ui()
            elif choice == '3':
                self.view_schedule_ui()
            elif choice == '4':
                break
            else:
                print("Invalid option, please try again.")