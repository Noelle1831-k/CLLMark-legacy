def check_level_completion(self):
        if self.board.is_cleared():
            self.score += 100 * self.level
            self.next_level()