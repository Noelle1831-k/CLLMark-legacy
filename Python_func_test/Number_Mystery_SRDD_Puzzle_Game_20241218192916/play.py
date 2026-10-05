def play(self, puzzle):
        player_solution = self.input_solution(len(puzzle.numbers))
        self.has_solved = puzzle.check_solution(player_solution)
        self.receive_feedback(self.has_solved)