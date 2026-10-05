def move(self, direction):
        '''
        Updates the player's position based on the given direction.
        '''
        directions = {
            'N': (-1, 0),
            'S': (1, 0),
            'E': (0, 1),
            'W': (0, -1)
        }
        if direction in directions:
            dx, dy = directions[direction]
            self.position = (self.position[0] + dx, self.position[1] + dy)