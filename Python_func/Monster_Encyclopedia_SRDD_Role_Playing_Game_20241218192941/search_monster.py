def search_monster(self, name):
        '''
        Search for a monster by name.
        '''
        return next((monster for monster in self.monsters if monster.name == name), None)