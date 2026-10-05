def run(self):
        self.load_data()
        while True:
            self.display_menu()
            choice = self.handle_input()
            if choice == '1':
                self.create_meeting()
            elif choice == '2':
                self.add_feedback()
            elif choice == '3':
                self.view_feedback()
            elif choice == '4':
                self.save_data()
                sys.exit()