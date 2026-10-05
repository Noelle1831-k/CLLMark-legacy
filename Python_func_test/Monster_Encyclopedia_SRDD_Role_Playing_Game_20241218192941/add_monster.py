def add_monster(self, monster):
        '''
        Add a new monster to the database.
        '''
        if isinstance(monster, Monster):
            self.monsters.append(monster)
        else:
            raise ValueError("Invalid monster object.")