def run(self):
        self.ui_manager.render_main_screen()
        while True:
            self.ui_manager.handle_user_input()