def start_game(self):
        self.board.initialize_board()
        while not self.check_game_over():
            self.player.make_move(self.board)
            self.board.clear_matches()
            self.board.apply_gravity()
            self.moves += 1
            self.check_for_powerups()
            if self.board.is_level_cleared():
                self.next_level()