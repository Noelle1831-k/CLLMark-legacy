def add_move(self, player, move, state):
        self.moves.append(Move(player, move, state))
        self.states.append(state)