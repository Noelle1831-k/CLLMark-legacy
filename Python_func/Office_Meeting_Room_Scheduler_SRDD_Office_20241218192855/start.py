def start(self):
        while True:
            print("\nOffice Meeting Room Scheduler")
            print("1. Book a Room")
            print("2. Release a Room")
            print("3. List Available Rooms")
            print("4. View Room Schedule")
            print("5. Exit")
            choice = input("Enter your choice: ")
            if choice == '1':
                room_number = input("Enter room number to book: ")
                date = input("Enter booking date (YYYY-MM-DD): ")
                start_time = input("Enter start time (HH:MM): ")
                end_time = input("Enter end time (HH:MM): ")
                print(self.scheduler.book_room(room_number, date, start_time, end_time))
            elif choice == '2':
                room_number = input("Enter room number to release: ")
                print(self.scheduler.release_room(room_number))
            elif choice == '3':
                print("Available Rooms:")
                print(self.scheduler.list_available_rooms())
            elif choice == '4':
                room_number = input("Enter room number to view schedule: ")
                print(self.scheduler.view_room_schedule(room_number))
            elif choice == '5':
                print("Exiting...")
                break
            else:
                print("Invalid choice. Please try again.")