def mark_monster_defeated(self, name):
        '''
        Mark a monster as defeated by name.
        '''
        for monster in self.monsters:
            if monster.name == name:
                monster.mark_defeated()
                return True
        return False