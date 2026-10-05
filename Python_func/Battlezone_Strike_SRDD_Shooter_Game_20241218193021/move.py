def move(self, direction):
        '''
        Updates the tank's position based on direction input.
        '''
        deltas = {'up': (0, 1), 'down': (0, -1), 'left': (-1, 0), 'right': (1, 0)}
        if direction in deltas:
            self.position[0] += deltas[direction][0] * self.speed
            self.position[1] += deltas[direction][1] * self.speed
        print(f"{self.name} moved to position {self.position}")