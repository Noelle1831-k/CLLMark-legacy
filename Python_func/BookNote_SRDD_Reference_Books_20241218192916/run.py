def run(self):
        while True:
            self.display_menu()
            choice = input("Enter choice: ")
            if choice == '7':
                break
            self.handle_input(choice)