def get_game_state(self):
        return self.states[-1] if self.states else None