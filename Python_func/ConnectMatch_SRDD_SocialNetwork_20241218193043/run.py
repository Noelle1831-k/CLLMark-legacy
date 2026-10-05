def run(self):
        while True:
            print("\n1. Create User")
            print("2. Find Matches")
            print("3. Display All Users")
            print("4. Exit")
            choice = input("Choose an option: ")
            if choice == "1":
                self.create_user()
            elif choice == "2":
                self.find_matches()
            elif choice == "3":
                self.display_all_users()
            elif choice == "4":
                print("Exiting the application.")
                break
            else:
                print("Invalid option. Try again.")