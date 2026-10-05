def run(self):
        # Main application loop
        while True:
            print("Welcome to ConnectHive!")
            print("1. Create Profile")
            print("2. Search Beekeepers")
            print("3. Share Knowledge")
            print("4. Visit Marketplace")
            print("5. Exit")
            choice = input("Enter your choice: ")
            if choice == '1':
                self.create_profile()
            elif choice == '2':
                self.search_beekeepers()
            elif choice == '3':
                self.share_knowledge()
            elif choice == '4':
                self.visit_marketplace()
            elif choice == '5':
                print("Exiting ConnectHive. Goodbye!")
                break
            else:
                print("Invalid choice. Please try again.")