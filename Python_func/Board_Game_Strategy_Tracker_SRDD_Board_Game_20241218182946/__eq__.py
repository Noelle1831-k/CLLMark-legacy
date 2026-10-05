def __eq__(self, other):
        if isinstance(other, Move):
            return (self.player == other.player and 
                    self.move == other.move and 
                    self.state == other.state)
        return False