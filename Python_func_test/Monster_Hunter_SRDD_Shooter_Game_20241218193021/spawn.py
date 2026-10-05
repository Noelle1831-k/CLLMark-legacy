def spawn(self):
        '''
        Spawn the monster in the game world with a random position.
        '''
        self.is_spawned = True
        position_x = random.randint(0, 100)
        position_y = random.randint(0, 100)
        print(f"{self.name} ({self.monster_type}) has spawned at position ({position_x}, {position_y})!")