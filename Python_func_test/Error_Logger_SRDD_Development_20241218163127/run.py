def run(self):
        while True:
            print("\nError Logger Dashboard")
            print("1. Log Error")
            print("2. Search Errors")
            print("3. Filter Errors")
            print("4. Display All Errors")
            print("5. Exit")
            choice = input("Enter your choice: ")
            if choice == '1':
                self.log_error()
            elif choice == '2':
                self.search_errors()
            elif choice == '3':
                self.filter_errors()
            elif choice == '4':
                self.display_errors()
            elif choice == '5':
                break
            else:
                print("Invalid choice. Please try again.")