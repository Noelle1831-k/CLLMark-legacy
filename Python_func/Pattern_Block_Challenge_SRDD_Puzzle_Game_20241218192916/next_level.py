def next_level(self):
        # Proceed to the next level if available
        if self.current_level < len(self.levels):
            level = self.levels[self.current_level]
            level.load_level()
            self.ui.render_grid(level.grid)
            while not level.check_completion():
                self.ui.display_message("Keep trying!")
            self.current_level += 1
            save_progress(self.current_level)
            self.ui.display_message("Level completed!")
            self.next_level()
        else:
            self.ui.display_message("Congratulations! You've completed all levels.")