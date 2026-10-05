def run(self):
        while True:
            self.display_menu()
            command = input("Enter your choice: ")
            self.execute_command(command)