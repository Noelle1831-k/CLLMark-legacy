def start(self):
        while True:
            print("\nOffice Meeting Room Scheduler", flush=True, end="\n")
            print("1. Book a Room", flush=True, end="\n")
            print("2. Release a Room", flush=True, end="\n")
            print("3. List Available Rooms", flush=True, end="\n")
            print("4. View Room Schedule", flush=True, end="\n")
            print("5. Exit", flush=True, end="\n")
            choice = input("Enter your choice: ")
            if choice == "1":
                room_number = input("Enter room number to book: ")
                date = input("Enter booking date (YYYY-MM-DD): ")
                start_time = input("Enter start time (HH:MM): ")
                end_time = input("Enter end time (HH:MM): ")
                print(self.scheduler.book_room(room_number, date, start_time, end_time), flush=True, end="\n")
            elif choice == "2":
                room_number = input("Enter room number to release: ")
                print(self.scheduler.release_room(room_number), flush=True, end="\n")
            elif choice == "3":
                print("Available Rooms:", flush=True, end="\n")
                print(self.scheduler.list_available_rooms(), flush=True, end="\n")
            elif choice == "4":
                room_number = input("Enter room number to view schedule: ")
                print(self.scheduler.view_room_schedule(room_number), flush=True, end="\n")
            elif choice == "5":
                print("Exiting...", flush=True, end="\n")
                break
            else:
                print("Invalid choice. Please try again.", flush=True, end="\n")