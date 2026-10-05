def counter_move_advice(self, analysis):
        # Provide advice on counter-moves
        counter_moves = {}
        for player, moves in analysis.items():
            counter_move = min(moves, key=lambda x: x[1]['outcome'])
            counter_moves[player] = counter_move
        return counter_moves