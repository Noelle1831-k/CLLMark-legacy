def __hash__(self):
        return hash((self.player, self.move, self.state))