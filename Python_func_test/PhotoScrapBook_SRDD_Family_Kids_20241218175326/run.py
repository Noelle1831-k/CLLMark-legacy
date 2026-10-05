def run(self):
        print("Welcome to PhotoScrapBook!")
        while True:
            choice = input("1. Login\n2. Register\n3. Exit\nChoose an option: ")
            if choice == '1':
                self.login()
            elif choice == '2':
                self.register()
            elif choice == '3':
                break
            else:
                print("Invalid choice. Please try again.")