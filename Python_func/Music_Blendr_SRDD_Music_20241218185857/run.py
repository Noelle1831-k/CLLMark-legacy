def run(self):
        self.ui.display_welcome_message()
        while True:
            choice = self.ui.get_user_choice()
            if choice == '1':
                self.import_tracks()
            elif choice == '2':
                self.mix_tracks()
            elif choice == '3':
                self.apply_effects()
            elif choice == '4':
                self.save_mix()
            elif choice == '5':
                self.ui.display_exit_message()
                break
            else:
                self.ui.display_invalid_choice()