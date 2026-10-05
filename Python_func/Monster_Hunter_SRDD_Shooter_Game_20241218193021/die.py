def die(self):
        '''
        Handle the monster's death, dropping loot and removing it from the game.
        '''
        self.is_spawned = False
        print(f"{self.name} ({self.monster_type}) has been defeated!")
        self.drop_loot()