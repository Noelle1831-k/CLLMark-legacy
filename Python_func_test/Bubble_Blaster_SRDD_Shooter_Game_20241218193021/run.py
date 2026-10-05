def run(self):
        while True:
            self.check_events()
            self.update_game()
            self.update_screen()