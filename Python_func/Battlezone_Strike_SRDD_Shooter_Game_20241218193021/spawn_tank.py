def spawn_tank(self, player):
        '''
        Places a tank at a random position within the arena.
        '''
        import random
        x = random.randint(0, self.width)
        y = random.randint(0, self.height)
        player.tank.position = [x, y]
        self.tanks.append(player.tank)
        print(f"Spawned {player.username}'s tank at {x}, {y}.")