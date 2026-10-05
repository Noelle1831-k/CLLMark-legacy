def evaluate_moves(self, state):
        # Evaluate possible moves and their outcomes
        moves = []
        for move in state['possible_moves']:
            outcome = self.simulate_move(move, state)
            moves.append((move, outcome))
        return moves