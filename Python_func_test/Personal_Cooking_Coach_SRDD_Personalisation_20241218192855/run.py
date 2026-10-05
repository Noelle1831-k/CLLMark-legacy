def run(self):
        while True:
            self.display_menu()
            choice = input("Enter your choice: ")
            self.handle_user_input(choice)