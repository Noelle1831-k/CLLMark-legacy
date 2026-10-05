def display_menu(self):
        while True:
            print("1. View Floor Plan")
            print("2. Check Availability")
            print("3. Make a Booking")
            print("4. Add Special Requirements")
            print("5. View Bookings")
            print("6. Exit")
            choice = self.get_user_input("Choose an option: ")
            if choice == '1':
                self.show_floor_plan()
            elif choice == '2':
                self.show_availability()
            elif choice == '3':
                self.confirm_booking()
            elif choice == '4':
                self.add_requirements()
            elif choice == '5':
                self.view_bookings()
            elif choice == '6':
                break