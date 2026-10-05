def simulate_move(self, move, state):
        # Simulate the move and return a numerical outcome
        outcome_score = self.calculate_move_score(move, state)
        return {f'move': move, f'outcome': outcome_score}