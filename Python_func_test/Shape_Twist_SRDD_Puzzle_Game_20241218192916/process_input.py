def process_input(self, user_input):
        if user_input == 'check':
            if self.check_solution():
                self.ui.update_display('Congratulations! You"ve solved the puzzle.')
                self.is_running = False
            else:
                self.ui.update_display('Try again!')
        elif user_input == 'reset':
            self.reset_game()
        elif user_input.startswith('rotate'):
            try:
                shape_index = int(user_input.split()[1])
                self.shapes[shape_index].rotate()
                self.ui.display_game(self.shapes, self.silhouette)
            except (IndexError, ValueError):
                self.ui.update_display('Invalid shape index.')
        elif user_input.startswith('flip'):
            try:
                shape_index = int(user_input.split()[1])
                self.shapes[shape_index].flip()
                self.ui.display_game(self.shapes, self.silhouette)
            except (IndexError, ValueError):
                self.ui.update_display('Invalid shape index.')
        else:
            self.ui.update_display('Invalid command.')