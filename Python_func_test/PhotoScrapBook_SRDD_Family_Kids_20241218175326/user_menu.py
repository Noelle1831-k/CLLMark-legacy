def user_menu(self, user):
        while True:
            choice = input("1. Create Scrapbook\n2. View Scrapbooks\n3. Share Scrapbook\n4. View Shared Scrapbooks\n5. Logout\nChoose an option: ")
            if choice == '1':
                self.create_scrapbook(user)
            elif choice == '2':
                self.view_scrapbooks(user)
            elif choice == '3':
                self.share_scrapbook(user)
            elif choice == '4':
                self.view_shared_scrapbooks(user)
            elif choice == '5':
                break
            else:
                print("Invalid choice. Please try again.")