def run(self):
        while True:
            self.display_menu()
            try:
                choice = int(input("Enter your choice: "))
                self.execute_choice(choice)
            except ValueError:
                print("Please enter a valid number.")