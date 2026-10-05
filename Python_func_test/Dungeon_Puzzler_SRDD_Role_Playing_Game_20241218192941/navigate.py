def navigate(self, direction, player):
        '''
        Navigates the player to a new room based on the direction.
        '''
        x, y = player.position
        moves = {
            "N": (x - 1, y),
            "S": (x + 1, y),
            "E": (x, y + 1),
            "W": (x, y - 1)
        }
        if direction in moves:
            new_x, new_y = moves[direction]
            if 0 <= new_x < len(self.layout) and 0 <= new_y < len(self.layout[0]):
                player.position = (new_x, new_y)
                self.current_room = (new_x, new_y)
                return True
        return False